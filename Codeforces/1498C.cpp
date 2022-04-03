#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=1005;
const int MOD=1e9+7;

LL dp[maxn][maxn],sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,0,n)rep(j,1,k)dp[i][j]=0;
        dp[0][k]=1;
        rep(i,0,n)sum[i]=1;
        LL ans=1;
        per(i,k-1,1){
            if((k-i)&1){
                rep(j,1,n){
                    dp[j][i]=sum[j-1];
                    (ans+=dp[j][i])%=MOD;
                }
                sum[n+1]=0;
                per(j,n,1)(sum[j]=sum[j+1]+dp[j][i])%=MOD;
            }
            else{
                rep(j,1,n-1){
                    dp[j][i]=sum[j+1];
                    (ans+=dp[j][i])%=MOD;
                }
                sum[0]=0;
                rep(j,1,n)(sum[j]=sum[j-1]+dp[j][i])%=MOD;
            }
            // printf("debug:%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}