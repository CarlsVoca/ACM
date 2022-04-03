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
    int L,cnt=0;
    scanf("%d",&L);
    do_main();
    rep(i,1,nump){
        if(L>=prime[i]){
            printf("%d\n",prime[i]);
            cnt++;
            L-=prime[i];
        }
        else break;
    }
    printf("%d\n",cnt);
    return 0;
}