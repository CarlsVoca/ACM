#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;
const int maxe=(2*maxn+maxn*maxn)*2;

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

int a[maxn],b[maxn];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        nume=-1;
        memset(last,-1,sizeof(last));
        int n;
        scanf("%d",&n);
        int S=0,T=2*n+1;
        rep(i,1,n){
            scanf("%d",&a[i]);
            if(a[i])add_edge(n+i,T,1);
        }
        int cnt=0;
        rep(i,1,n){
            scanf("%d",&b[i]);
            if(a[i]==0)add_edge(S,i,1),cnt++;
            else if(b[i]==0)add_edge(S,i,1),cnt++;
        }
        rep(i,1,n){
            rep(j,1,n){
                int x;
                scanf("%d",&x);
                if(i==j)add_edge(i,n+j,1);
                else if(x)add_edge(i,n+j,1);
            }
        }
        if(Dinic::do_main(S,T)==cnt)puts("^_^");
        else puts("T_T");
    }
    return 0;
}