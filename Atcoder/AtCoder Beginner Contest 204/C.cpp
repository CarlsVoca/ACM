#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=2005;

struct Edge{
    int u,v,nxt;
}e[maxn<<1];
int nume=0,last[maxn];
void add_edge(int u,int v){
    e[++nume]=(Edge){u,v,last[u]};
    last[u]=nume;
}

int n,m;
bool vis[maxn];
int ans=0;

void dfs(int u){
    vis[u]=1;ans++;
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(vis[v])continue;
        dfs(v);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    rep(i,1,n){
        memset(vis,0,sizeof(vis));
        dfs(i);
    }
    printf("%d\n",ans);
    return 0;
}