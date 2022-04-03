#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

struct Edge{
	int u,v,nxt;
}e[maxn*maxn];
int nume=0;
int last[maxn];

inline void add_edge(int u,int v){
	e[++nume]=(Edge){u,v,last[u]};
	last[u]=nume;
}

int n,m;

namespace Hungarian{
	int result[maxn];
	bool vis[maxn];
	bool dfs(int u){
		for(int i=last[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(!vis[v]){
				vis[v]=1;
				if(!result[v]||dfs(result[v])){
					result[v]=u;
                    result[u]=v;
					return 1;
				}
			}
		}
		return 0;
	}
	int do_main(){
		int cnt=0;
		for(int i=1;i<=m;i++){
			memset(vis,0,sizeof(vis));
			cnt+=dfs(i);
		}
		return cnt;
	}
}
using namespace Hungarian;

int main()
{
	scanf("%d%d",&m,&n);
	int u,v;
	while(scanf("%d%d",&u,&v)){
        if(u==-1&&v==-1)break;
        add_edge(u,v);
    }
    printf("%d\n",do_main());
    for(int i=1;i<=m;i++){
        if(result[i])printf("%d %d\n",i,result[i]);
    }
	return 0;
}