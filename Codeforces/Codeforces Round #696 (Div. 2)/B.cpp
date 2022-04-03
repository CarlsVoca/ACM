#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

namespace Sieve_of_Euler{
    int nump=0,prime[maxn];
    bool is_prime[maxn];
    void do_main(){
        memset(is_prime,1,sizeof(is_prime));
        is_prime[1]=0;
        for(int i=2;i<maxn;i++){
            if(is_prime[i])prime[++nump]=i;
            for(int j=1;j<=nump&&prime[j]*i<maxn;j++){
                is_prime[i*prime[j]]=0;
                if(i%prime[j]==0)break;
            }
        }
    }
}
using namespace Sieve_of_Euler;

int main(){
    do_main();
    // printf("debug:%d\n",prime[lower_bound(prime+1,prime+nump,+1)-prime]);
    int T;
    scanf("%d",&T);
    while(T--){
        LL d;
        scanf("%lld",&d);
        LL x=prime[lower_bound(prime+1,prime+nump+1,1+d)-prime];
        LL y=prime[lower_bound(prime+1,prime+nump+1,x+d)-prime];
        // printf("%lld %lld\n",x,y);
        printf("%lld\n",x*y);
    }
    return 0;
}