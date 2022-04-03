#include<cstdio> 
#include<cstring>
#include<iostream>

using namespace std;

const int maxn=15;

int b[maxn]; 

int main()
{
	int a;
	cin>>a;
	if(a<0){
		a=-a;
		printf("-");
	}
	else if(a==0){
		printf("0\n");
		return 0;
	}
	int num=0;
	while(a){
		b[++num]=a%10;
		a/=10;
	}
	bool flag=0;
	for(int i=1;i<=num;i++){
		if(b[i]==0&&!flag){
			continue;
		}
		flag=1;
		cout<<b[i];
	}
	return 0;
}

