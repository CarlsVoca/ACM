#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1000005;

int l[maxn],r[maxn],ans=0;

void dfs(int u,int dep){
    ans=max(ans,dep);
    if(l[u])dfs(l[u],dep+1);
    if(r[u])dfs(r[u],dep+1);
}

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}