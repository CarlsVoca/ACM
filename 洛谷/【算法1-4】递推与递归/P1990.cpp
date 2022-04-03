#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1000005;

int dp[maxn][3];

int main(){
    int n;
    scanf("%d",&n);
    dp[0][0]=1;
    bool flag=0;
    rep(i,1,n){
        if(i==1){
            dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
            dp[i][1]=dp[i-1][2];
            dp[i][2]=dp[i-1][1];    
        }
        else if(i>=2){
            dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-2][0];
            dp[i][1]=dp[i-2][0]+dp[i-1][2];
            dp[i][2]=dp[i-2][0]+dp[i-1][1];
        }
        if(dp[i][0]>9999||dp[i][1]>9999||dp[i][2]>9999)flag=1;
        rep(j,0,2)dp[i][j]%=10000;
    }
    if(flag)printf("%04d\n",dp[n][0]);
    else printf("%d\n",dp[n][0]);
    return 0;
}