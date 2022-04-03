#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int num[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
					{31,29,31,30,31,30,31,31,30,31,30,31}};

int leap(int n){
	return (n%4==0)&&(!(n%100==0)||(n%400==0));
}

int main(){
	int day=1,ans=0;
	for(int i=1900;i<=2000;i++){
		int is_leap=leap(i);
		for(int j=0;j<12;j++){
			day+=num[is_leap][j];
			if(day%7==0&&i>1900)ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
