#include<bits/stdc++.h>

using namespace std;

const int maxn=305;

int w[maxn],dp[maxn][maxn],sz[maxn];
vector<int> son[maxn];

void dfs(int u,int k){
    sz[u]=1;
    if(!k)return;
    dp[u][1]=w[u];
    for(int i=0;i<son[u].size();i++){
        int v=son[u][i];
        dfs(v,k-1);
        for(int j=k;j>=2;j--){
            for(int l=min(j-1,sz[v]);l>=1;l--){
                dp[u][j]=max(dp[u][j],dp[v][l]+dp[u][j-l]);
            }
        }
        sz[u]+=sz[v];
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u;
        scanf("%d%d",&u,&w[i]);
        son[u].push_back(i);
    }
    dfs(0,m+1);
    printf("%d\n",dp[0][m+1]);
    return 0;
}