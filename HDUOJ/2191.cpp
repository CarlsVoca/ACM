#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

int p[maxn],h[maxn],c[maxn];
int dp[maxn][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,m)scanf("%d%d%d",&p[i],&h[i],&c[i]);
        rep(i,1,m){
            rep(j,0,n){
                if(j!=0)dp[i][j]=dp[i][j-1];
                rep(k,0,c[i]){
                    if(j-k*p[i]<0)break;
                    else dp[i][j]=max(dp[i][j],dp[i-1][j-k*p[i]]+h[i]*k);
                }
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}