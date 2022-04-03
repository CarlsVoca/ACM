#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
	LL n;
	scanf("%lld",&n);
	int ans=0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	printf("%d\n",ans);
	return 0;
}