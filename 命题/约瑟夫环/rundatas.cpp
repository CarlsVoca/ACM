#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

const int maxn=1e9;

int random(int MIN,int MAX){
	return rand()%(MAX-MIN+1)+MIN;
}

int main()
{
	freopen("11.in","w",stdout);
	srand(time(0));
	int T=1000000;
	printf("%d\n",T);
	while(T--){
		int n,k;
		// if(T<=100){
		// 	n=random(2,maxn);
		// 	k=2;
		// }
		// else if(T<=200){
		// 	k=random(3,1000);
		// 	n=900000000/(k-1)*(k-1)+random(2,k-1);
		// }
		// else if(T<=300){
		// 	k=random(3,maxn);
		// 	n=random(2,k-1);
		// }
		// else{
		// 	k=random(3,1000)
		// 	n=900000000/(k-1)*(k-1)+1;
		// }
		n=1e9;
		k=2;
		printf("%d %d\n",n,k);
	}
	return 0;
}