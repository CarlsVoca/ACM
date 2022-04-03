#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=65;
const int INF=0x3f3f3f3f;

int g[maxn][maxn];

struct Edge{
	int u,v,nxt;
}e[maxn*maxn];
int nume=0,last[maxn];
void add_edge(int u,int v){
	e[++nume]=(Edge){u,v,last[u]};
	last[u]=nume;
}

namespace Tarjan{
	int dfn[maxn],low[maxn],color[maxn],val[maxn],a[maxn];
	int sta[maxn],top;
	int dfnnum=0,colnum=0;
	bool vis[maxn];
	void do_main(int u){
		dfn[u]=low[u]=++dfnnum;
		vis[u]=1;
		sta[++top]=u;
		for(int i=last[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(!dfn[v]){
				do_main(v);
				low[u]=min(low[u],low[v]);
			}
			else if(vis[v])low[u]=min(low[u],dfn[v]);
		}
		if(dfn[u]==low[u]){
			colnum++;
			while(sta[top]!=u){
				color[sta[top]]=colnum;
				vis[sta[top]]=0;
				val[colnum]+=a[sta[top--]];
			}
			color[sta[top]]=colnum;
			vis[sta[top]]=0;
			val[colnum]+=a[sta[top--]];
		}
	}
}
using namespace Tarjan;

int n;

namespace Topo_Sort{
	int degree[maxn];
	int topo[maxn],num=0;
	queue<int>q;
	bool do_main(){
		for(int i=1;i<=n;i++){
			if(!degree[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			topo[++num]=u;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(--degree[v]==0)q.push(v);
			}
		}
		if(num!=n)return 1;
		else return 0;
	}
}
using namespace Topo_Sort;

LL vec[maxn];
int nid[maxn];
bool viss[maxn][maxn];

void dfs(int s,int u){
	viss[s][u]=1;
	for(int i=last[u];i;i=e[i].nxt){
		if(viss[s][e[i].v])continue;
		dfs(s,e[i].v);
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1,n)a[i]=1;
	rep(i,1,n)rep(j,1,n){
		scanf("%1d",&g[i][j]);
		if(g[i][j])add_edge(i,j);
	}
	rep(i,1,n)if(!color[i])Tarjan::do_main(i);
	
	memset(last,0,sizeof(last));
	nume=0;
	rep(i,1,n)rep(j,1,n){
		if(g[i][j]&&color[i]!=color[j])add_edge(color[i],color[j]),degree[color[j]]++;
	}
	n=colnum;
	rep(i,1,n)dfs(i,i);
	// rep(u,1,n){
	// 	for(int i=last[u];i;i=e[i].nxt){
	// 		vec[u]|=(1LL<<e[i].v);
	// 	}
	// }
	Topo_Sort::do_main();
	// rep(i,1,n/2)swap(topo[i],topo[n-(i-1)]);
	// rep(i,1,n)nid[topo[i]]=i;
	LL ans=1;
	rep(i,1,n){
		int cnt=0;
		rep(j,i+1,n){
			if(!viss[topo[i]][topo[j]])cnt++;
		}
		ans+=(1LL<<cnt);
	}
	printf("%lld\n",ans);
	return 0;
}