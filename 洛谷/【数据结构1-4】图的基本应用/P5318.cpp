#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
const int maxm=1e6+5;

struct Edge{
    int u,v,w,nxt;
}e[maxm];

int nume=0,last[maxn];

inline void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

bool vis[maxn];
int cnt=0;
int n,m;

void dfs(int u){
    if(vis[u])return;
    if((++cnt)!=1)putchar(' ');
    printf("%d",u);
    vis[u]=1;
    vector<int> vec;
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(vis[v])continue;
        else vec.push_back(v);
    }
    sort(vec.begin(),vec.end());
    rep(i,0,(LL)vec.size()-1LL)dfs(vec[i]);
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    if((++cnt)!=1)putchar(' ');
    printf("%d",s);
    vis[s]=1;
    while(!q.empty()){
        vector<int> vec;
        int u=q.front();q.pop();
        for(int i=last[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(vis[v])continue;
            else vec.push_back(v);
        }
        sort(vec.begin(),vec.end());
        rep(i,0,(LL)vec.size()-1LL){
            q.push(vec[i]);
            if((++cnt)!=1)putchar(' ');
            printf("%d",vec[i]);
            vis[vec[i]]=1;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,1);
    }
    dfs(1);
    putchar('\n');
    cnt=0;
    memset(vis,0,sizeof(vis));
    bfs(1);
    putchar('\n');
    return 0;
}