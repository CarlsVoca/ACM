#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;
const int maxm=100005;

struct Edge{
    int u,v,w,nxt;
}e[maxm<<1];
int last[maxn],nume=0;

void add_edge(int u,int v,int w){
    e[++nume]=Edge{u,v,w,last[u]};
    last[u]=nume;
}

namespace SPFA{
	int cnt[maxn];
	bool vis[maxn];
	LL dis[maxn];
	bool do_main(int s){
		queue<int>q;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		vis[s]=1;
		dis[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=0;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dis[v]>dis[u]+e[i].w){
					dis[v]=dis[u]+e[i].w;
					if(!vis[v]){
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
		return 1;
	}
}
using namespace SPFA;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    do_main(1);
    printf("%lld\n",dis[n]);
    return 0;
}