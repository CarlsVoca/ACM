#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int a[maxn];
int n,m;

struct Edge{
    int u,v,nxt;
}e[maxn<<1];
int nume=0,last[maxn];

void add_edge(int u,int v){
    e[++nume]=Edge{u,v,last[u]};
    last[u]=nume;
}

int xsum[maxn];

namespace LCA{
	int dep[maxn],f[maxn][22];
	void dfs(int u){
        xsum[u]=xsum[f[u][0]]^a[u];
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

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1);
    pre();
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        int lca=do_main(u,v);
        printf("%d\n",xsum[u]^xsum[v]^a[lca]);
    }
    return 0;
}