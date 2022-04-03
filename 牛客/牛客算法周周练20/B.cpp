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
    int v,k;
    scanf("%d%d",&v,&k);
    v=max(v,k);
    LL ans=0;
    ans=(ans+do_main(2,0))%MOD;
    rep(i,v/2-(k-2)/2+1,v/2)ans=(ans+do_main(2,i-1))%MOD;
    ans=(ans+do_main(2,v-1))%MOD;
    rep(i,v/2+1,v/2+(k-2)/2)ans=(ans+do_main(2,i-1))%MOD;
    printf("%lld\n",ans);
    return 0;
}