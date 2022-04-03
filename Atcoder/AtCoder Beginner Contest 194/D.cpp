#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

double dp[maxn];

int main(){
    int n;
    scanf("%d",&n);
    dp[n]=0;
    per(i,n-1,1)dp[i]=((n-i)*dp[i+1]/n+1)*n/(n-i);
    printf("%lf\n",dp[1]);
    return 0;
}