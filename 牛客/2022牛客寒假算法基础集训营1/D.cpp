#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;
const double eps=1e-7;

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
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(n==1){
            puts("-1");
            continue;
        }
        LL MIN=1;
        rep(i,1,nump){
            if(MIN*prime[i]<=n)MIN*=prime[i];
        }
        LL MAX;
        per(i,n,2){
            bool flag=1;
            for(int j=2;j*j<=n;j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
            if(flag){
                MAX=i;
                break;
            }
        }
        printf("%lld %lld\n",MIN,MAX);
    }
    return 0;
}