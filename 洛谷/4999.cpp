#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=20;
const int MOD=1e9+7;

LL dp[maxn][10][10];

void init(){
    rep(i,0,9)dp[1][i][i]=1;
    LL t=10;
    rep(i,2,maxn-1){
        rep(j,0,9){
            rep(k,0,9){
                if(j==k)dp[i][j][k]=(dp[i][j][k]+t)%MOD;
                rep(l,0,9){
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][l][k])%MOD;
                }
            }
        }
        t*=10;
    }
    return;
}

LL solve(LL x){
    int digit[maxn],len=0;
    LL ans[10];
    memset(ans,0,sizeof(ans));
    while(x){digit[++len]=x%10;x/=10;}
    LL tmp[maxn];
    tmp[0]=0;
    LL t=1;
    rep(i,1,len){
        tmp[i]=digit[i]*t+tmp[i-1];
        t*=10;
    }
    per(i,len,1){
        rep(j,0+(i==len),digit[i]-1+(i==1)){
            rep(k,0,9){
                ans[k]=(ans[k]+dp[i][j][k])%MOD;
            }
        }
        if(i!=1)ans[digit[i]]=(ans[digit[i]]+tmp[i-1]+1)%MOD;
    }
    rep(i,1,len-1){
        rep(j,1,9){
            rep(k,0,9){
                ans[k]=(ans[k]+dp[i][j][k])%MOD;
            }
        }
    }
    LL res=0;
    rep(i,1,9){
        res=(res+ans[i]*i%MOD)%MOD;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    init();
    while(T--){
        LL a,b;
        scanf("%lld%lld",&a,&b);
        // printf("%lld\n",solve(a-1));
        printf("%lld\n",((solve(b)-solve(a-1))%MOD+MOD)%MOD);
    }
    return 0;
}