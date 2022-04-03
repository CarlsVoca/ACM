#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m=0;
void ac(int a)
{
	for(int i=1;i<=a/2;++i)
	  ac(i);
	m++;
}
int main()
{
	scanf("%d",&n);
	ac(n);
	printf("%d",m);
    return 0;
}