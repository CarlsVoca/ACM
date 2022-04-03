#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

const int maxn=1000;

int random(int MIN,int MAX){
	return rand()%(MAX-MIN+1)+MIN;
}

int main()
{
	freopen("13.in","w",stdout);
	srand(time(0));
	int T=random(1e6,1e6);
	printf("%d\n",T);
	while(T--){
		int b=random(1,31622);
		int n=b*b,m=random(1,1e9);
		printf("%d %d\n",n,m);
	}
	return 0;
}