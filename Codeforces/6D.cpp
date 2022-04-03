#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=17;

int dp[maxn][maxn][maxn],c[maxn];

int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    rep(i,1,n){
        scanf("%d",&c[i]);
    }
    memset(dp,0x3f,sizeof(dp));
    rep(i,c[1]/b+1,16)dp[2][0][i]=i;
    rep(i,3,n-1){
        rep(j,0,16){
            rep(k,0,16){
                rep(l,0,16){
                    if(j*a+k*b+l*b>c[i-1])dp[i][j][k]=min(dp[i][j][k],dp[i-1][l][j]+k);
                }
                // printf("%d %d %d\n",i,j,k);
            }
        }
    }
    int ans=INF;
    int last;
    rep(j,0,16)rep(k,0,16){
        if(j*b+k*a>c[n-1]&&k*b>c[n]){
            if(dp[n-1][j][k]<ans){
                ans=dp[n-1][j][k];
                last=k;
            }
        }
    }
    printf("%d\n",ans);
    per(i,n-1,2){
        rep(j,1,last)printf("%d ",i);
        c[i+1]-=last*b;
        c[i]-=last*a;
        c[i-1]-=last*b;
        rep(j,0,16){
            if((i==3?(j*b>c[3]&&j*a>c[2]&&j*b>c[1]):(j*b>c[i]))&&dp[i][j][last]==ans){
                ans-=last;
                last=j;
                break;
            }
        }
    }
    return 0;
}