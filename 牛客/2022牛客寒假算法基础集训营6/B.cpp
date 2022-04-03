#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;
const int MOD=998244353;

int a[maxn],b[maxn],tp,sz[maxn];

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
    int T;
    scanf("%ds",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        tp=0;
        rep(i,1,n){
            if(i==1||a[i]!=a[i-1]){
                b[++tp]=a[i];
                sz[tp]=1;
            }
            else{
                sz[tp]++;
            }
        }
        LL ans=1;
        rep(i,1,tp){
            if(i==1||i==tp||(b[i]>b[i-1]&&b[i]>b[i+1])||(b[i]<b[i-1]&&b[i]<b[i+1])){
                ans=ans*(do_main(2,sz[i])-1)%MOD;
            }
            else{
                ans=ans*do_main(2,sz[i])%MOD;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}