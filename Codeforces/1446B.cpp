#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5005;

int dp[maxn][maxn];
string a,b;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    cin>>a>>b;
    int ans=0;
    rep(i,1,n)
        rep(j,1,m){
            if(a[i-1]==b[j-1])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
            else dp[i][j]=max(dp[i][j],max(dp[i-1][j]-1,dp[i][j-1]-1));
            ans=max(ans,dp[i][j]);
        }
    printf("%d\n",ans);
    return 0;
}