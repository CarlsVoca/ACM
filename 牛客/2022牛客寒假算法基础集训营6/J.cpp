#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10000005;
const int MOD=998244353;

int cnt[4];
LL fac[maxn],two[maxn];

namespace Quick_Pow{
	LL do_main(LL a,LL k){
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
    fac[0]=1;
    two[0]=1;
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,1,n)fac[i]=fac[i-1]*i%MOD;
    rep(i,1,n)two[i]=two[i-1]*2%MOD;
    // printf("%lf\n",clock());
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    if(cnt[1]+cnt[2]<k){
        puts("0");
    }
    else{
        LL ans=0;
        LL tmp=fac[cnt[1]]*fac[cnt[2]]%MOD;
        for(int i=max(0,k-cnt[2]);i<=min(k,cnt[1]);i++){
            int j=k-i;
            ans+=tmp*do_main(fac[cnt[1]-i]*fac[i]%MOD*fac[cnt[2]-j]%MOD*fac[j]%MOD,MOD-2)%MOD*two[j]%MOD;
            ans%=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}