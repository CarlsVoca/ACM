#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;
const int MOD=1e9+7;

LL dp[maxn];

int main(){
    int n;
    scanf("%d",&n);
    dp[3]=4;
    rep(i,4,n)dp[i]=dp[i-1]*2%MOD;
    LL ans=1;
    rep(i,2,n)ans=ans*i%MOD;
    printf("%lld\n",((ans-dp[n])%MOD+MOD)%MOD);
    return 0;
}