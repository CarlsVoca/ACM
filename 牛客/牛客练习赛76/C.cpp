#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int MOD=1e9+7;

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
    int T;
    scanf("%d",&T);
    while(T--){
        LL n,m;
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",do_main(m,n-1)*(n-1)%MOD*(m-1)%MOD*do_main(2,MOD-2)%MOD*3%MOD);
    }
    return 0;
}