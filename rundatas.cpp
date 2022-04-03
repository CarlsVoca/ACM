#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

const int maxa=1000;
const int maxb=1000000;

int random(int MIN,int MAX){
	return rand()%(MAX-MIN+1)+MIN;
}

int main()
{
	freopen("test.in","w",stdout);
	srand(time(0));
	int T=5;
	printf("%d\n",T);
	while(T--){
		int n=5,x=random(1,3);
		printf("%d %d\n",n,x);
		rep(i,1,n)printf("%d ",random(1,5));
		putchar('\n');
	}
	return 0;
}