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

int n,m;

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
		q.push(s);cnt[s]++;
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=0;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dis[v]>dis[u]+e[i].w){
					dis[v]=dis[u]+e[i].w;
					if(!vis[v]){
						vis[v]=1;
						q.push(v);cnt[v]++;
                        if(cnt[v]>n)return 0;
					}
				}
			}
		}
		return dis[n]<INF;
	}
}
using namespace SPFA;

int main(){
    while(scanf("%d%d",&n,&m)){
        memset(last,0,sizeof(last));
        nume=0;
        if(n==0&&m==0)break;
        rep(i,1,m){
            int u,v,w1,w2;
            scanf("%d%d%d%d",&u,&v,&w1,&w2);
            add_edge(u,v,w1);
            add_edge(v,u,w2);
        }
        if(!do_main(1))puts("No such path");
        else printf("%lld\n",dis[n]);
    }
    return 0;
}