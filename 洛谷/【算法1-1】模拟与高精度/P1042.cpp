#include<cstdio> 
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

char a[100003];
int num=0;

void work(int n)
{
	if(num==0)printf("0:0\n");
	int couW=0,couL=0; 
	for(int i=1;i<=num;i++){
		a[i]=='W'?couW++:couL++;
		if(abs(couW-couL)>=2&&(couW>=n||couL>=n)){
			printf("%d:%d\n",couW,couL);
			couW=0;
			couL=0;
		}
		else if(i==num){
			printf("%d:%d\n",couW,couL);
		}
	}
	if(num&&num%n==0)printf("%d:%d\n",0,0);
}

int main()
{
	char ch=' ';
	while(ch!='W'&&ch!='L'&&ch!='E')ch=getchar();
	while(ch!='E'){
		a[++num]=ch;
		ch=getchar();
		while(ch!='W'&&ch!='L'&&ch!='E')ch=getchar();
	}
	work(11);
	printf("\n");
	work(21);
	return 0;
}
