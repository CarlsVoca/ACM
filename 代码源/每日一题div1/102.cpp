#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int n;
int a[maxn];
int dp[maxn];

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    rep(i,1,n){
        dp[i]=1;
        rep(j,1,i-1){
            if(a[i]%a[j]==0){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}