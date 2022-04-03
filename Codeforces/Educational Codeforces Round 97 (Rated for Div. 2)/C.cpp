#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int t[maxn],dp[maxn][maxn<<1];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&t[i]);
        sort(t+1,t+n+1);
        rep(i,1,n)rep(j,1,2*n)dp[i][j]=INF;
        rep(i,1,2*n)dp[1][i]=abs(i-t[1]);
        rep(i,2,n)
            rep(j,1,2*n)
                rep(k,1,j-1){
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(j-t[i]));
                }
        int ans=INF;
        rep(i,1,2*n)ans=min(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}