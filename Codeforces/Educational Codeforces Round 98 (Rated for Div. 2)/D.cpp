#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;
const int MOD=998244353;

namespace Quick_Pow{
    LL do_main(LL a,int k){
        LL r=1,base=a;
        while(k){
            if(k&1)r=(r*base)%MOD;
            base=(base*base)%MOD;
            k>>=1;
        }
        return r%MOD;
    }
}
using namespace Quick_Pow;

int main(){
    int n;
    scanf("%d",&n);
    LL sum1=1,sum2=0,dp=0;
    rep(i,2,n+1){
        if(i&1)dp=sum2;
        else dp=sum1;
        if(i&1)sum1+=dp;
        else sum2+=dp;
        sum1%=MOD;
        sum2%=MOD;
    }
    // printf("debug:%lld\n",dp);
    printf("%lld\n",dp*do_main(do_main(2,n),MOD-2)%MOD);
    return 0;
}