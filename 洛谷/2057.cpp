#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=305;
const int maxe=200005;

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
/*
Note:
    memset(last,-1,sizeof(last));
    nume从0开始 
*/
    int dep[maxn],pre[maxn];
    bool bfs(int s,int t){
        queue<int> q;
        memset(dep,-1,sizeof(dep));
        dep[s]=0;
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
                int new_flow=dfs(v,t,min(e[i].f,rest));
                rest-=new_flow;
                e[i].f-=new_flow;
                e[i^1].f+=new_flow;
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
    int n,m;
    scanf("%d%d",&n,&m);
    int S=0,T=n+1;
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        if(x==0){
            add_edge(S,i,1);
            add_edge(i,T,0);
        }
        else{
            add_edge(S,i,0);
            add_edge(i,T,1);    
        }
    }
    rep(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,1);
        add_edge(v,u,1);
    }
    printf("%d\n",Dinic::do_main(S,T));
    return 0;
}