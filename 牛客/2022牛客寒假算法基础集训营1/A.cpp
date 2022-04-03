#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
const int MOD=998244353;

int a[maxn];
LL dp[maxn][10];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
        a[i]%=9;
    }
    // dp[1][a[1]]=1;
    rep(i,1,n){
        rep(j,0,8){
            dp[i][j]=dp[i-1][j]+dp[i-1][(j-a[i]+9)%9];
            dp[i][j]%=MOD;
        }
        dp[i][a[i]]++;
    }
    rep(i,1,9){
        printf("%lld ",dp[n][i%9]);
    }
    return 0;
}