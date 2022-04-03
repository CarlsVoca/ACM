#include<bits/stdc++.h>

using namespace std;

const int maxn=40005;
const int maxm=100005;

int st[maxn],ed[maxn],d[maxn*2],a[maxn],p=0,used[maxn],ans[maxm],n,m,cnt[maxn];

struct Edge{
    int u,v,nxt;
}e[maxn<<1];
int nume=0,last[maxn];

void add_edge(int u,int v){
    e[++nume]=Edge{u,v,last[u]};
    last[u]=nume;
}

namespace Discretization{
    int tmp[maxn];
    void do_main(int arr[],int size){
        memcpy(tmp+1,arr+1,size<<2);
        sort(tmp+1,tmp+size+1);
        int m=unique(tmp+1,tmp+size+1)-tmp-1;
        for(int i=1;i<=size;i++)arr[i]=lower_bound(tmp+1,tmp+m+1,arr[i])-tmp;
    }
}

namespace LCA{
	int dep[maxn],f[maxn][22];
	void dfs(int u){
		for(int i=last[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(v!=f[u][0]){
				f[v][0]=u;
				dep[v]=dep[u]+1;
				dfs(v);
			}
		}
	}
	void pre(){
		for(int j=1;(1<<j)<=n;j++)
			for(int i=1;i<=n;i++){
				f[i][j]=f[f[i][j-1]][j-1];
			}
	}
	int do_main(int a,int b){
		if(dep[a]<dep[b])swap(a,b);
		int dif=dep[a]-dep[b];
		for(int i=0;(1<<i)<=dif;i++){
			if((1<<i)&dif)a=f[a][i];
		}
		if(a!=b){
			for(int i=(int)log2(n);i>=0;i--){
				if(f[a][i]!=f[b][i]){
					a=f[a][i];b=f[b][i];
				}
			}
			a=f[a][0];b=f[b][0];
		}
		return a;
	}
}

int bsz;
struct Query{
    int l,r,id,tp,lca;
    bool operator < (const Query &b)const{
        return l/bsz==b.l/bsz?r<b.r:l/bsz<b.l/bsz;
    }
}q[maxm];

void dfs(int u){
    d[++p]=u;st[u]=p;
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(st[v])continue;
        dfs(v);
    }
    d[++p]=u;ed[u]=p;
}

int main(){
    scanf("%d%d",&n,&m);
    bsz=sqrt(2*n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    Discretization::do_main(a,n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1);
    LCA::dfs(1);
    LCA::pre();
    for(int i=1;i<=m;i++){
        q[i].id=i;
        int u,v;
        scanf("%d%d",&u,&v);
        if(st[u]>st[v])swap(u,v);
        if((q[i].lca=LCA::do_main(u,v))==u){
            q[i].l=st[u];
            q[i].r=st[v];
            q[i].tp=1;
        }
        else{
            q[i].l=ed[u];
            q[i].r=st[v];
            q[i].tp=2;
        }
    }
    sort(q+1,q+m+1);
    int l=1,r=0,res=0;
    for(int i=1;i<=m;i++){
        while(r<q[i].r){
            r++;
            if(used[d[r]]==0)cnt[a[d[r]]]++,res+=(cnt[a[d[r]]]==1);
            else if(used[d[r]]==1)cnt[a[d[r]]]--,res-=(cnt[a[d[r]]]==0);
            used[d[r]]++;
        }
        while(r>q[i].r){
            if(used[d[r]]==2)cnt[a[d[r]]]++,res+=(cnt[a[d[r]]]==1);
            else if(used[d[r]]==1)cnt[a[d[r]]]--,res-=(cnt[a[d[r]]]==0);
            used[d[r]]--;
            r--;
        }
        while(l<q[i].l){
            if(used[d[l]]==2)cnt[a[d[l]]]++,res+=(cnt[a[d[l]]]==1);
            else if(used[d[r]]==1)cnt[a[d[l]]]--,res-=(cnt[a[d[l]]]==0);
            used[d[l]]--;
            l++;
        }
        while(l>q[i].l){
            l--;
            if(used[d[l]]==0)cnt[a[d[l]]]++,res+=(cnt[a[d[l]]]==1);
            else if(used[d[l]]==1)cnt[a[d[l]]]--,res-=(cnt[a[d[l]]]==0);
            used[d[l]]++;
        }
        ans[q[i].id]=res+(cnt[a[q[i].lca]]==0);
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}