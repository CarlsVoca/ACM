#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

int main(){
	int n;
	scanf("%d",&n);
	double jwj;
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		double rat=y/1.0/x;
		if(i==1){
			jwj=rat;
		}
		else{
			if(rat-jwj>0.05)puts("better");
			else if(jwj-rat>0.05)puts("worse");
			else puts("same");
		}
	}
	return 0;
}