#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=205;

struct Edge{
    int u,v,w,nxt;
}e[maxn<<1];

int nume=0,last[maxn];

inline void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

namespace Dijkstra{
    typedef pair<int,int> pii;
    int dis[maxn];
    void do_main(int s){
        priority_queue< pii,vector<pii>,greater<pii> >q;
        memset(dis,0x3f,sizeof(dis));
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

int a[maxn];

int main(){
    int n,A,B;
    scanf("%d%d%d",&n,&A,&B);
    rep(i,1,n){
        scanf("%d",&a[i]);
        if(i+a[i]<=n)add_edge(i,i+a[i],1);
        if(i-a[i]>=1)add_edge(i,i-a[i],1);
    }
    do_main(A);
    if(dis[B]==INF)puts("-1");
    else printf("%d\n",dis[B]);
    return 0;
}