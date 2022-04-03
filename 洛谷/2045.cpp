#include<bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=55*55*2;
const int maxe=maxn*6;

struct Edge{
    int u,v,f,c,nxt;
}e[maxe];
int nume=-1,last[maxn];

void add_edge(int u,int v,int f,int c){
    e[++nume]=Edge{u,v,f,c,last[u]};
    last[u]=nume;
    e[++nume]=Edge{v,u,0,-c,last[v]};
    last[v]=nume;
}

namespace MFMC{
    int dis[maxn],pe[maxn],pv[maxn];
    bool vis[maxn];
    bool SPFA(int s,int t){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[s]=0;
        queue<int> q;
        vis[s]=1;
        q.push(s);
        while(!q.empty()){
            int u=q.front();q.pop();vis[u]=0;
            for(int i=last[u];~i;i=e[i].nxt){
                int v=e[i].v;
                if(dis[v]>dis[u]+e[i].c&&e[i].f){
                    dis[v]=dis[u]+e[i].c;
                    pe[v]=i;pv[v]=u;
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        return dis[t]<INF;
    }
    int do_main(int s,int t){
        memset(pe,-1,sizeof(pe));
        int cost=0,flow=0;
        while(SPFA(s,t)){
            int new_flow=INF;
            for(int i=pe[t];~i;i=pe[e[i].u])new_flow=min(new_flow,e[i].f);
			//for(int i=t;i!=s;i=pv[i])new_flow=min(new_flow,e[pe[i]].f);
            cost+=dis[t];
            flow+=new_flow;
            for(int i=pe[t];~i;i=pe[e[i].u])e[i].f-=new_flow,e[i^1].f+=new_flow;
            //for(int i=t;i!=s;i=pv[i])e[pe[i]].f-=new_flow,e[pe[i]^1].f+=new_flow;
        }
        return cost;
    }
}

/*
namespace MFMC{
	typedef pair<int,int> pii;
	int q[maxn*maxn],pe[maxn],pv[maxn],dis[maxn];
	bool vis[maxn];
	namespace SPFA{
		bool do_main(int s,int t){
			int head=1,tail=0;
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));	
			dis[s]=0;
			vis[s]=1;
			q[++tail]=s;
			while(head<=tail){
				int u=q[head++];
				vis[u]=0;
				for(int i=last[u];~i;i=e[i].nxt){
					int v=e[i].v;
					if(e[i].f&&dis[v]>dis[u]+e[i].c){
						dis[v]=dis[u]+e[i].c;
						pe[v]=i,pv[v]=u;
						if(!vis[v]){
							vis[v]=1;
							q[++tail]=v;
						}
					}
				}
			}
			return dis[t]<INF;
		}
	}
	pii do_main(int s,int t){
		int cost=0,flow=0;
		while(SPFA::do_main(s,t)){
			int new_flow=INF;
			for(int i=t;i!=s;i=pv[i])new_flow=min(new_flow,e[pe[i]].f);
			cost+=new_flow*dis[t];
			flow+=new_flow;
			for(int i=t;i!=s;i=pv[i])e[pe[i]].f-=new_flow,e[pe[i]^1].f+=new_flow;
		}
		return pii(cost,flow);
	}
}
*/
int main(){
    memset(last,-1,sizeof(last));
    int n,k;
    scanf("%d%d",&n,&k);
    int S=0,T=n*n*2+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            add_edge((i-1)*n+j,(i-1)*n+j+n*n,INF,0);
            add_edge((i-1)*n+j,(i-1)*n+j+n*n,1,-x);
        }
    add_edge(S,1,k,0);add_edge(2*n*n,T,k,0);
    for(int i=1;i<n;i++)for(int j=1;j<=n;j++)add_edge((i-1)*n+j+n*n,i*n+j,INF,0);
    for(int i=1;i<=n;i++)for(int j=1;j<n;j++)add_edge((i-1)*n+j+n*n,(i-1)*n+j+1,INF,0);
    printf("%d\n",-MFMC::do_main(S,T));
    return 0;
}