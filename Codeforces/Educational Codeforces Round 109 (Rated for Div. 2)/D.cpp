#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef pair<int,int> pii;

const int maxn=5005;
const int INF=0x3f3f3f3f;

/*
struct Edge{
    int u,v,f,c,nxt;
}e[maxn*maxn];
int last[maxn],nume=-1;

void add_edge(int u,int v,int f,int c){
    e[++nume]=(Edge){u,v,f,c,last[u]};
    last[u]=nume;
    e[++nume]=(Edge){v,u,0,-c,last[v]};
    last[v]=nume;
}

int x[maxn];

namespace MFMC{
	int pe[maxn],dis[maxn];
	bool vis[maxn];
	namespace Dijkstra{
		bool do_main(int s,int t){
			priority_queue< pii,vector<pii>,greater<pii> >q;
			memset(dis,0x3f,sizeof(dis));
			dis[s]=0;
			q.push(pii(0,s));
			while(!q.empty()){
				pii now=q.top();q.pop();
				int u=now.second;
				if(dis[u]<now.first)continue;
				for(int i=last[u];~i;i=e[i].nxt){
					int v=e[i].v;
					if(e[i].f&&dis[u]+e[i].c<dis[v]){
						dis[v]=dis[u]+e[i].c;
						pe[v]=i;
						q.push(pii(dis[v],v));
					}
				}
			}
			return dis[t]<INF;
		}
	}
	namespace SPFA{
		bool do_main(int s,int t){
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));
			dis[s]=0;
			queue<int> q;
			vis[s]=1;
			q.push(s);
			while(!q.empty()){
				int u=q.front();q.pop();
				vis[u]=0;
				for(int i=last[u];~i;i=e[i].nxt){
					int v=e[i].v;
					if(e[i].f&&dis[v]>dis[u]+e[i].c){
						dis[v]=dis[u]+e[i].c;
						pe[v]=i;
						if(!vis[v]){
							vis[v]=1;
							q.push(v);
						}
					}
				}
			}
			return dis[t]<INF;
		}
	}
	pii do_main(int s,int t){
        memset(pe,-1,sizeof(pe));
		int cost=0,flow=0;
		while(Dijkstra::do_main(s,t)){
			int new_flow=INF;
			for(int i=pe[t];~i;i=pe[e[i].u])new_flow=min(new_flow,e[i].f);
			cost+=new_flow*dis[t];
			flow+=new_flow;
			for(int i=pe[t];~i;i=pe[e[i].u])e[i].f-=new_flow,e[i^1].f+=new_flow;
		}
		return pii(cost,flow);
	}
}
using namespace MFMC;

int main(){
    memset(last,-1,sizeof(last));
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&x[i]);
    }
    int S=0,T=n+1;
    rep(i,1,n){
        if(x[i])add_edge(S,i,1,0);
        else add_edge(i,T,1,0);
    }
    rep(i,1,n){
        if(x[i]){
            rep(j,1,n){
                if(!x[j]){
                    add_edge(i,j,1,abs(i-j));
                }
            }
        }
    }
    printf("%d\n",do_main(S,T).first);
    return 0;
}
*/

int a[maxn],pos[maxn];
int dp[maxn][maxn];

int main(){
	int n,id=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i])pos[++id]=i;
	}
	memset(dp,0x3f,sizeof(dp));
	rep(i,0,n)dp[i][0]=0;
	rep(i,1,n){
		rep(j,1,id){
			if(a[i]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(pos[j]-i));
			}
			// printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",dp[n][id]);
	return 0;
}