#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=5005;

LL a[maxn],b[maxn],pre[maxn],neg[maxn];
LL dp[maxn][maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n)scanf("%d",&b[i]);
    pre[0]=0;
    rep(i,1,n)pre[i]=pre[i-1]+a[i]*b[i];
    neg[n+1]=0;
    per(i,n,1)neg[i]=neg[i+1]+a[i]*b[i];
    rep(i,1,n)dp[i][i]=a[i]*b[i];
    rep(i,1,n-1){dp[i][i+1]=a[i]*b[i+1]+a[i+1]*b[i];}
    rep(len,3,n){
        rep(i,1,n-len+1){
            int j=i+len-1;
            dp[i][j]=dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i];
        }
    }
    LL ans=0;
    rep(i,1,n){
        rep(j,i,n){
            ans=max(ans,dp[i][j]+pre[i-1]+neg[j+1]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}