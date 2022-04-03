#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

namespace Quick_Pow{
	LL do_main(LL a,int k){
    	LL r=1,base=a;
		while(k){
        	if(k&1)r=r*base;
        	base=base*base;
        	k>>=1;
    	}
    	return r;
	}
}
using namespace Quick_Pow;

int main(){
    clock_t st=clock();
    freopen("11.in","r",stdin);
    freopen("11.out","w",stdout);
    int T;
	scanf("%d",&T);
	while(T--){
		LL n,k;
		scanf("%lld%lld",&n,&k);
		if(k!=2&&(n%(k-1)!=1||n<k))puts("NO");
		else{
			puts("YES");
			int t=ceil(log(n)/log(k)-1);
			LL tmp=do_main(k,t);
			while(tmp>=n)tmp/=k,t--;//误差修正
			while(tmp*k<n)tmp*=k,t++;//误差修正
			// printf("t=%d\n",t);
			printf("%lld\n",(n-tmp)/(k-1)*k);
		}
	}
    clock_t ed=clock();
    printf("used time=%lf\n",(double)(ed-st)/CLOCKS_PER_SEC);
	return 0;
}