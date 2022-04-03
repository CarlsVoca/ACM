#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=(1LL<<60);
const int maxn=505;

int a[maxn];
LL dp[maxn][maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n)rep(j,i,n)dp[i][j]=INF;
    rep(i,2,n-1){
        dp[i][i]=a[i-1]*a[i]*a[i+1];
    }
    rep(len,2,n-2){
        for(int i=2,j;(j=i+len-1)<=n-1;i++){
            rep(k,i,j){
                dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]*a[i-1]*a[j+1]);
            }
        }
    }
    printf("%lld\n",dp[2][n-1]);
    return 0;
}