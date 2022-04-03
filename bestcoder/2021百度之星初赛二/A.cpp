#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int MOD=998244353;

namespace Quick_Pow{
	LL do_main(LL a,int k){
    	LL r=1,base=a;
		while(k){
        	if(k&1)r=r*base%MOD;
        	base=base*base%MOD;
        	k>>=1;
    	}
    	return r;
	}
}
using namespace Quick_Pow;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL a,b,k;
        scanf("%lld%lld%lld",&a,&b,&k);
        if(k&1){
            int t=k/2;
            LL aa=a*do_main(2,t)%MOD,bb=b*do_main(2,t)%MOD;
            printf("%lld %lld\n",(aa+bb)%MOD,((aa-bb)%MOD+MOD)%MOD);
        }
        else{
            int t=k/2;
            LL aa=a*do_main(2,t)%MOD,bb=b*do_main(2,t)%MOD;
            printf("%lld %lld\n",aa,bb);
        }
    }
    return 0;
}