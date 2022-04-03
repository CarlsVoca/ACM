#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=16;

int res[maxn],ans[maxn],ansMAX=0;
int n,k;
int dp[1005];

void dfs(int pre,int tp,int MAX){
    if(tp==k){
        if(MAX>ansMAX){
            ansMAX=MAX;
            rep(i,1,k)ans[i]=res[i];
        }
        return;
    }
    rep(i,pre+1,MAX+1){
        res[tp+1]=i;
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        rep(j,1,tp+1){
            rep(l,res[j],1000){
                dp[l]=min(dp[l],dp[l-res[j]]+1);
            }
        }
        rep(j,1,1000){
            if(dp[j]>n){
                dfs(i,tp+1,j-1);
                break;
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&k);
    dfs(0,0,0);
    rep(i,1,k)printf("%d ",ans[i]);
    printf("\nMAX=%d\n",ansMAX);
    return 0;
}