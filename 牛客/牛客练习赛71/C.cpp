#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2005;
const int MOD=20000311;

LL dp[maxn][maxn],p[maxn],sum[2][maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m)scanf("%lld",&p[i]);
    sort(p+1,p+m+1);
    int tmp=1;
    rep(i,1,n){
        dp[1][i]=1;
        if(i==1&&tmp<=m&&p[1]==1){
            tmp++;
            dp[1][1]=0;
        }
        sum[1][i]=sum[1][i-1]+dp[1][i];
        // printf("debug:dp[%d][%d]=%lld\n",1,i,dp[1][i]);
    }
    rep(i,2,n){
        sum[i&1][i-1]=0;
        rep(j,i,n){
            dp[i][j]=(sum[i&1^1][j-1]+dp[i-1][j]*(j-i+1))%MOD;
            if(tmp<=m&&p[tmp]==i&&j==i){
                dp[i][j]=0;tmp++;
            }
            sum[i&1][j]=(sum[i&1][j-1]+dp[i][j])%MOD;
            // printf("debug:dp[%d][%d]=%lld\n",i,j,dp[i][j]);
        }
    }
    printf("%lld\n",dp[n][n]);
    return 0;
}