#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=10000;
const int maxn=205;
const int maxe=(105+605*2)*2;

struct Edge{
    int u,v,f,nxt;
}e[maxe];

int nume=-1,last[maxn];

inline void add_edge(int u,int v,int f){
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
    int dfs(int u,int t,int cur){
        if(u==t)return cur;
        int rest=cur;
        for(int &i=pre[u];~i;i=e[i].nxt){
            int v=e[i].v;
            if(dep[v]==dep[u]+1&&e[i].f){
                int newf=dfs(v,t,min(rest,e[i].f));
                rest-=newf;
                e[i].f-=newf;
                e[i^1].f+=newf;
                if(!rest)return cur;
            }
        }
        return cur-rest;
    }
    int do_main(int s,int t){
        int res=0;
        while(bfs(s,t)){
            memcpy(pre,last,sizeof(last));
            res+=dfs(s,t,INF);
        }
        return res;
    }
}

int main(){
    memset(last,-1,sizeof(last));
    int n,m,S,T;
    scanf("%d%d%d%d",&n,&m,&S,&T);
    rep(i,1,n){
        if(i==S||i==T)continue;
        add_edge(i,n+i,1);
    }
    rep(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==S||u==T||v==T|v==S){
            if((u==S||u==T)&&(v==T||v==S)){
                add_edge(u,v,INF);
                add_edge(v,u,INF);
            }
            else if(u==S||u==T){
                add_edge(u,v,INF);
                add_edge(n+v,u,INF);
            }
            else if(v==T||v==S){
                add_edge(n+u,v,INF);
                add_edge(v,u,INF);
            }
        }
        else{
            add_edge(n+u,v,INF);
            add_edge(n+v,u,INF);
        }
    }
    printf("%d\n",Dinic::do_main(S,T));
    return 0;
}