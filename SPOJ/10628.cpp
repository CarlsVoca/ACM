#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int ll,rr,L[10],R[10],n,m,a[maxn],T[maxn];

struct Edge{
	int u,v,nxt;
}e[maxn<<1];
int nume;
int last[maxn];

inline void add_edge(int u,int v){
	e[++nume]=(Edge){u,v,last[u]};
	last[u]=nume;
}

namespace Discretization{
	int tmp[maxn],new_size;
	void do_main(int arr[],int size){
		memcpy(tmp,arr,sizeof(tmp));
		sort(tmp+1,tmp+1+size);
		new_size=unique(tmp+1,tmp+size+1)-tmp-1;
		for(int i=1;i<=size;i++)arr[i]=lower_bound(tmp+1,tmp+new_size+1,arr[i])-tmp;
	}
}
using namespace Discretization;

namespace Faction_Segment_Tree{
	struct Node{
		int ls,rs,sum;
	}t[maxn*30];
	int sz=0;
	int Update(int pre,int l,int r,int x,int k){
		int now=++sz;
		t[now]=t[pre];t[now].sum+=k;
		if(l<r){
			int mid=l+r>>1;
			if(mid>=x)t[now].ls=Update(t[pre].ls,l,mid,x,k);
			else t[now].rs=Update(t[pre].rs,mid+1,r,x,k);
		}
		return now;
	}
	int Query(int l,int r,int k){
		if(l==r)return l;
		int suml=0,sumr=0;
		for(int i=1;i<=ll;i++)suml+=t[t[L[i]].ls].sum;
		for(int i=1;i<=rr;i++)sumr+=t[t[R[i]].ls].sum;
		int del=sumr-suml;
		int mid=l+r>>1;
		if(del>=k){
			for(int i=1;i<=ll;i++)L[i]=t[L[i]].ls;
			for(int i=1;i<=rr;i++)R[i]=t[R[i]].ls;
			return Query(l,mid,k);
		}
		else{
			for(int i=1;i<=ll;i++)L[i]=t[L[i]].rs;
			for(int i=1;i<=rr;i++)R[i]=t[R[i]].rs;
			return Query(mid+1,r,k-del);
		}
	}
}
using namespace Faction_Segment_Tree;

namespace LCA{
	int dep[maxn],f[maxn][22];
	void dfs(int u){
		T[u]=Update(T[f[u][0]],1,new_size,a[u],1);
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
using namespace LCA;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	Discretization::do_main(a,n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
	LCA::dfs(1);LCA::pre();
	for(int i=1,u,v,k;i<m;i++){
		scanf("%d%d%d",&u,&v,&k);
		int lca=LCA::do_main(u,v);
//		printf("LCA=%d\n",lca);
		ll=0;rr=0;
		L[++ll]=T[lca];L[++ll]=T[f[lca][0]];R[++rr]=T[u];R[++rr]=T[v];
		printf("%d\n",tmp[Query(1,new_size,k)]);
	}
	for(int i=m,u,v,k;i<=m;i++){
		scanf("%d%d%d",&u,&v,&k);
		int lca=LCA::do_main(u,v);
//		printf("LCA=%d\n",lca);
		ll=0;rr=0;
		L[++ll]=T[lca];L[++ll]=T[f[lca][0]];R[++rr]=T[u];R[++rr]=T[v];
		printf("%d",tmp[Query(1,new_size,k)]);
	}
	return 0;
}