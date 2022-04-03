#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int MOD=1e9+7;

LL quick_pow(LL a,LL k){
	LL r=1,base=a;
	while(k){
    	if(k&1)r=r*base%MOD;
    	base=base*base%MOD;
    	k>>=1;
	}
	return r;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        LL tmp=quick_pow(2,n);
        LL ans=(tmp-2)*m%MOD*quick_pow(tmp,MOD-2)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}