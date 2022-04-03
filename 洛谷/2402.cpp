#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=1000000000000000000LL;
const int maxn=405;
const int maxe=(maxn*maxn+2*maxn)*2;

struct Edge{
    int u,v;
    LL f;
    int nxt;
}e[maxe];

int nume=-1,last[maxn];

inline void add_edge(int u,int v,LL f){
    e[++nume]=(Edge){u,v,f,last[u]};
    last[u]=nume;
    e[++nume]=(Edge){v,u,0,last[v]};
    last[v]=nume;
}

namespace Dinic{
    int dep[maxn],pre[maxn];
    bool bfs(int s,int t){
        memset(dep,-1,sizeof(dep));
        dep[s]=0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=last[u];~i;i=e[i].nxt){
                int v=e[i].v;
                if(dep[v]==-1&&e[i].f){
                    dep[v]=dep[u]+1;
                    q.push(v);
                    if(v==t)return 1;
                }
            }
        }
        return 0;
    }
    LL dfs(int u,int t,LL cur){
        if(u==t)return cur;
        LL rest=cur;
        for(int &i=pre[u];~i;i=e[i].nxt){
            int v=e[i].v;
            if(dep[v]==dep[u]+1&&e[i].f){
                LL newf=dfs(v,t,min(rest,e[i].f));
                rest-=newf;
                e[i].f-=newf;
                e[i^1].f+=newf;
                if(!rest)return cur;
            }
        }
        return cur-rest;
    }
    LL do_main(int s,int t){
        LL res=0;
        while(bfs(s,t)){
            memcpy(pre,last,sizeof(last));
            res+=dfs(s,t,INF);
        }
        return res;
    }
}

int n,m,S,T;
LL sum=0;
LL dis[maxn][maxn];
LL s[maxn],p[maxn];

namespace Floyd{
    void do_main(){
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
    }
}
using namespace Floyd;

bool check(LL mid){
    memset(last,-1,sizeof(last));
    nume=-1;
    rep(i,1,n){
        add_edge(S,i,s[i]);
        add_edge(n+i,T,p[i]);
    }
    rep(i,1,n)rep(j,1,n){
        if(dis[i][j]<=mid)add_edge(i,n+j,INF);
    }
    if(Dinic::do_main(S,T)==sum)return 1;
    return 0;
}

int main(){
    // memset(last,-1,sizeof(last));
    scanf("%d%d",&n,&m);
    S=0,T=2*n+1;
    rep(i,1,n){
        scanf("%lld%lld",&s[i],&p[i]);
        sum+=s[i];
        // add_edge(S,i,s[i]);
        // add_edge(n+i,T,p[i]);
    }
    rep(i,1,n)rep(j,1,n)dis[i][j]=(i==j?0:INF);
    rep(i,1,m){
        int u,v;
        LL w;
        scanf("%d%d%lld",&u,&v,&w);
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
    }
    Floyd::do_main();
    // printf("debug:%lld\n",dis[2][3]);
    LL l=0,r=INF;
    while(l<r){
        LL mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l==INF?-1:l);
    // rep(i,1,n)add_edge(i,n+i,INF);
    // if(Dinic::do_main(S,T)==sum){puts("0");return 0;}
    // rep(i,1,n){
    //     rep(j,1,n){
    //         if(j-i>=1)add_edge(j,n+j-i,INF);
    //         if(j+i<=n)add_edge(j,n+j+i,INF);
    //     }
    //     if(Dinic::do_main(S,T)==sum){
    //         printf("%d\n",i);
    //         return 0;
    //     }
    // }
    return 0;
}