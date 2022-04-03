#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int MIN=0x7fffffff;
	int x,y;
	for(int i=1;i<=3;i++){
		scanf("%d%d",&x,&y);
		MIN=min(MIN,(n/x+(n%x==0?0:1))*y);
	}
	printf("%d\n",MIN);
	return 0;
}