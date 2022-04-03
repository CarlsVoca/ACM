#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5005;
const int MOD=1e9+7;

LL cnt[maxn];

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
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    LL ans=0,inv2=do_main(2,MOD-2);
    rep(i,1,5000){
        if(cnt[i]>=2){
            rep(j,0,(i-1)/2)ans+=cnt[j]*cnt[i-j]%MOD*cnt[i]%MOD*(cnt[i]-1)%MOD*inv2%MOD,ans%=MOD;
            if(i%2==0)ans+=cnt[i/2]*(cnt[i/2]-1)%MOD*inv2%MOD*cnt[i]%MOD*(cnt[i]-1)%MOD*inv2%MOD,ans%=MOD;
        }
    }
    printf("%lld\n",ans);
    return 0;
}