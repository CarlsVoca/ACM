#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=65;

string s[maxn];
LL dp[maxn][2];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)cin>>s[i];
    dp[0][0]=dp[0][1]=1;
    rep(i,1,n){
        if(s[i]=="AND"){
            dp[i][0]+=dp[i-1][0]*2+dp[i-1][1];
            dp[i][1]+=dp[i-1][1];
        }
        else{
            dp[i][0]+=dp[i-1][0];
            dp[i][1]+=dp[i-1][0]+dp[i-1][1]*2;
        }
    }
    printf("%lld\n",dp[n][1]);
    return 0;
}