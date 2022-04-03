#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;

struct Edge{
    int u,v,w,nxt;
}e[maxn*2];

int nume=0,last[maxn];

inline void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

namespace Dijkstra{
    typedef pair<int,int> pii;
    int dis1[maxn],dis2[maxn];
    void do_main(int s,int dis[]){
        priority_queue< pii,vector<pii>,greater<pii> >q;
        dis[s]=0;
        q.push(pii(0,s));
        while(!q.empty()){
            pii now=q.top();q.pop();
            int u=now.second;
            if(dis[u]<now.first)continue;
            for(int i=last[u];i;i=e[i].nxt){
                int v=e[i].v;
                if(dis[u]+e[i].w<dis[v]){
                    dis[v]=dis[u]+e[i].w;
                    q.push(pii(dis[v],v));
                }
            }
        }
    }
}
using namespace Dijkstra;

int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    if(n==m){puts("0");return 0;}
    rep(i,0,p-1){
        add_edge(i,(i*2)%p,1);
        add_edge(i,(i+1)%p,1);
    }
    add_edge(n,(n*2)%p,1);
    add_edge(n,(n+1)%p,1);
    add_edge(m,(m*2)%p,1);
    add_edge(m,(m+1)%p,1);
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
    do_main(n,dis1);
    do_main(m,dis2);
    int ans=INF;
    rep(i,0,p-1)ans=min(ans,dis1[i]+dis2[i]);
    ans=min(ans,dis1[n]+dis2[n]);
    ans=min(ans,dis1[m]+dis2[m]);
    printf("%d\n",ans);
    return 0;
}