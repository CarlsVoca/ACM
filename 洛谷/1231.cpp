#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=300005;
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
    int dep[maxn],pre[maxn];
    bool bfs(int s,int t){
        queue<int> q;
        memset(dep,-1,sizeof(dep));
        dep[s]=1;
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
                int new_f=dfs(v,t,min(rest,e[i].f));
                rest-=new_f;
                e[i].f-=new_f;
                e[i^1].f+=new_f;
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

/*
namespace Dinic{
    int dep[maxn],pre[maxn],q[maxn*maxn];
    bool bfs(int s,int t){
        int head=1,tail=0;
        memset(dep,0,sizeof(dep));
        dep[s]=1;
        q[++tail]=s;
        while(head<=tail){
            int u=q[head++];
            for(int i=last[u];~i;i=e[i].nxt){
                int v=e[i].v;
                if(!dep[v]&&e[i].f){
                    dep[v]=dep[u]+1;
                    q[++tail]=v;
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
            if(dep[v]==dep[u]+1&&e[i].f&&rest){
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
        int ans=0;
        while(bfs(s,t)){
            memcpy(pre,last,sizeof(last));
            ans+=dfs(s,t,INF);
        }
        return ans;
    }
}
using namespace Dinic;
*/
int main(){
    memset(last,-1,sizeof(last));
    int n1,n2,n3;
    scanf("%d%d%d",&n1,&n2,&n3);
    int S=0,T=n1+n2+n3+1;
    rep(i,1,n2)add_edge(S,n1+i,1);
    rep(i,1,n3)add_edge(n1+n2+i,T,1);
    int m1,m2;
    scanf("%d",&m1);
    rep(i,1,m1){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(n1+y,x,1);
    }
    scanf("%d",&m2);
    rep(i,1,m2){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x+n1+n2+n3+1,n1+n2+y,1);
    }
    rep(i,1,n1)add_edge(i,i+n1+n2+n3+1,1);
    printf("%d\n",Dinic::do_main(S,T));
    return 0;
}