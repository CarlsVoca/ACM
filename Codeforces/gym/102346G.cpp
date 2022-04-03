#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=305;

int S,T;

struct Edge{
    int u,v,f;
    double c;
    int nxt;
}e[maxn*maxn*8];
int last[maxn],nume=-1;

void add_edge(int u,int v,int f,double c){
    e[++nume]=(Edge){u,v,f,c,last[u]};
    last[u]=nume;
    e[++nume]=(Edge){v,u,0,-c,last[v]};
    last[v]=nume;
}

namespace MFMC{
	typedef pair<int,int> pii;
	int q[maxn*maxn],pe[maxn],pv[maxn];
    double dis[maxn];
	bool vis[maxn];
	namespace SPFA{
		bool do_main(int s,int t){
			int head=1,tail=0;
			memset(vis,0,sizeof(vis));
			rep(i,S,T)dis[i]=INF;	
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
	void do_main(int s,int t){
		double cost=0;
        int flow=0;
		while(SPFA::do_main(s,t)){
			int new_flow=INF;
			for(int i=t;i!=s;i=pv[i])new_flow=min(new_flow,e[pe[i]].f);
			cost+=new_flow*dis[t];
			flow+=new_flow;
			for(int i=t;i!=s;i=pv[i])e[pe[i]].f-=new_flow,e[pe[i]^1].f+=new_flow;
		}
	}
}

double a[maxn][maxn];

int main(){
    memset(last,-1,sizeof(last));
    int n;
    scanf("%d",&n);
    S=0,T=2*n+1;
    rep(i,1,n)add_edge(S,i,1,0);
    rep(i,1,n)add_edge(n+i,T,1,0);
    rep(i,1,n){
        rep(j,1,n){
            scanf("%lf",&a[i][j]);
            a[i][j]=log2(a[i][j]);
            add_edge(j,n+i,1,-a[i][j]);
        }
    }
    MFMC::do_main(S,T);
    rep(u,1,n){
        for(int i=last[u];~i;i=e[i].nxt){
            if(e[i].f==0&&e[i].v!=S){
                printf("%d ",e[i].v-n);
                break;
            }
        }
    }
    return 0;
}