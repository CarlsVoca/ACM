#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5005;
const int MOD=1e9+7;

int b[maxn];
LL dp[maxn][maxn],sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n-1)scanf("%d",&b[i]);
        sum[1]=dp[1][1]=1;
        rep(i,2,n){
            rep(j,1,i){
                if(b[i-1]==0){
                    dp[i][j]=sum[j-1];
                }
                else{
                    dp[i][j]=((sum[i-1]-sum[j-1])%MOD+MOD)%MOD;
                }
                // printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
            }
            rep(j,1,i)sum[j]=(sum[j-1]+dp[i][j])%MOD;
        }
        printf("%lld\n",sum[n]);
    }
    return 0;
}