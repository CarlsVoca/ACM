#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;
const int MOD=1e9+7;

LL cnt[maxn],sum[maxn],fac[maxn];
int a[maxn];

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



LL C(LL n,LL m){
    if(m>n)return 0;
    return fac[n]*do_main(fac[n-m],MOD-2)%MOD*do_main(fac[m],MOD-2)%MOD;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        fac[0]=1;
        rep(i,1,n)fac[i]=fac[i-1]*i%MOD;
        rep(i,1,n)cnt[i]=0,sum[i]=0;
        rep(i,1,n){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        rep(i,1,n)sum[i]+=sum[i-1]+cnt[i];
        LL ans=0;
        rep(i,1,n){
            rep(j,1,min(m*1LL,cnt[i])){
                ans+=C(cnt[i],j)*C(sum[i-1]-sum[max(i-k-1,0)],m-j);
            }
        }
        printf("%lld\n",ans%MOD);
    }
    return 0;
}