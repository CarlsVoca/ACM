#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

struct Edge{
    int u,v,nxt;
}e[maxn<<1];
int last[maxn],nume=0;

void add_edge(int u,int v){
    e[++nume]=(Edge){u,v,last[u]};
    last[u]=nume;
}

int a[maxn],f[maxn],sum[maxn];

void dfs(int u){
    sum[u]=a[u];
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f[u])continue;
        f[v]=u;
        dfs(v);
        sum[u]^=sum[v];
    }
}

bool vis[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n)last[i]=0;
        nume=0;
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n-1){
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        dfs(1);
        if(sum[1]==0)puts("YES");
        else{
            bool flag=0;
            rep(i,2,n){
                if(sum[i]==sum[1]){
                    int p=f[i];
                    while(p){
                        if(sum[p]==0){flag=1;break;}
                        vis[p]=1;
                        p=f[p];
                    }
                    rep(j,i+1,n){
                        if(!vis[j]&&sum[j]==sum[1]){flag=1;break;}
                    }
                    p=f[i];
                    while(p){
                        vis[p]=0;
                        p=f[p];
                    }
                }
                if(flag)break;
            }
            if(flag&&k>=3)puts("YES");
            else puts("NO");
        }
    }
    return 0;
}