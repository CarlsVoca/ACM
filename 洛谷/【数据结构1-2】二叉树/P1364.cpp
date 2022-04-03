#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

int l[maxn],r[maxn],dep[maxn];
LL a[maxn],sz[maxn],ans;

void pre(int u){
    if(l[u]){
        dep[l[u]]=dep[u]+1;
        pre(l[u]);
    }
    if(r[u]){
        dep[r[u]]=dep[u]+1;
        pre(r[u]);
    }
    sz[u]=sz[l[u]]+sz[r[u]]+a[u];
}

void dfs(int u,LL res){
    ans=min(ans,res);
    if(l[u]){
        res-=sz[l[u]];
        res+=sz[1]-sz[l[u]];
        dfs(l[u],res);
        res+=sz[l[u]];
        res-=sz[1]-sz[l[u]];
    }
    if(r[u]){
        res-=sz[r[u]];
        res+=sz[1]-sz[r[u]];
        dfs(r[u],res);
        res+=sz[r[u]];
        res-=sz[1]-sz[r[u]];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d%d",&a[i],&l[i],&r[i]);
    pre(1);
    rep(i,1,n)ans+=dep[i]*a[i];
    dfs(1,ans);
    printf("%lld\n",ans);
    return 0;
}