#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2505;
const int maxm=6205;

struct Edge{
    int u,v,w,nxt;
}e[maxm<<1];
int last[maxn],nume=0;

void add_edge(int u,int v,int w){
    e[++nume]=Edge{u,v,w,last[u]};
    last[u]=nume;
}

LL dis[maxn];
bool vis[maxn];
int n,m,s,t;

void do_main(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    for(int T=1;T<=n;T++){
        int MIN=INF,u;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dis[i]<MIN){
                MIN=dis[i];
                u=i;
            }
        }
        for(int i=last[u];i;i=e[i].nxt){
            int v=e[i].v;
            dis[v]=min(dis[v],dis[u]+e[i].w);
        }
        vis[u]=1;
    }
}

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    rep(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    do_main();
    printf("%lld\n",dis[t]);
    return 0;
}