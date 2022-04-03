#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;
const int MOD=1e9+7;

string s[maxn];
LL dp[maxn];

int main(){
    // freopen("E.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)cin>>s[i];
        dp[0]=1;dp[1]=1;
        rep(i,2,n){
            if(s[i]==s[i-1])dp[i]=dp[i-1];
            else dp[i]=(dp[i-2]+dp[i-1])%MOD;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}