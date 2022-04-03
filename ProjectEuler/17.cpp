#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
//1-19
const int c1[]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
//20 30 40 50 60 70 80 90
const int c2[]={0,0,6,6,5,5,5,7,6,6};
const int Hundred=7;
const int And=3;
const int Thousand=8;

int main(){
	int ans=0;
	for(int i=1;i<=19;i++)ans+=c1[i];
	for(int i=20;i<100;i++){
		ans+=c2[i/10]+c1[i%10];
	}
	for(int i=1;i<10;i++){
		ans+=c1[i]+Hundred;
		for(int j=1;j<=19;j++){
			ans+=c1[i]+Hundred+And+c1[j];
		}
		for(int j=20;j<100;j++){
			ans+=c1[i]+Hundred+And+c2[j/10]+c1[j%10];
		}
	}
	ans+=c1[1]+Thousand;
	printf("%d\n",ans);
	return 0;
}
