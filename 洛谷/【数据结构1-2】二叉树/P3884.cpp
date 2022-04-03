#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

struct Edge{
    int u,v,w,nxt;
}e[maxn<<1];

int nume=0,last[maxn];

inline void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

int n;
int cnt[maxn];

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
using namespace LCA;

namespace Discretization{
	int tmp[maxn*2],uu[maxn],vv[maxn],m;
	void do_main(){
        rep(i,1,n-1)tmp[i]=uu[i];
        rep(i,n,2*n-2)tmp[i]=vv[i-n+1];
		sort(tmp+1,tmp+2*n-1);
		m=unique(tmp+1,tmp+2*n-1)-tmp-1;
		for(int i=1;i<=n-1;i++)uu[i]=lower_bound(tmp+1,tmp+m+1,uu[i])-tmp;
        for(int i=1;i<=n-1;i++)vv[i]=lower_bound(tmp+1,tmp+m+1,vv[i])-tmp;
	}
}
using namespace Discretization;

int main(){
    scanf("%d",&n);
    int u,v;
    rep(i,1,n-1)scanf("%d%d",&uu[i],&vv[i]);
    Discretization::do_main();
    // rep(i,1,n-1)printf("Debug:%d %d\n",uu[i],vv[i]);
    rep(i,1,n-1){
        add_edge(uu[i],vv[i],1);
        add_edge(vv[i],uu[i],1);
    }
    dfs(1);
    pre();
    int a=0,b=0;
    rep(i,1,n)cnt[dep[i]]++,a=max(a,dep[i]);
    rep(i,0,a)b=max(b,cnt[i]);
    printf("%d\n%d\n",a+1,b);
    scanf("%d%d",&u,&v);
    u=lower_bound(tmp+1,tmp+m+1,u)-tmp;
    v=lower_bound(tmp+1,tmp+m+1,v)-tmp;
    int lca=LCA::do_main(u,v);
    printf("%d\n",(dep[u]-dep[lca])*2+dep[v]-dep[lca]);
    return 0;
}