#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	int g=gcd(a[0],a[2]);
	a[0]/=g;
	a[2]/=g;
	printf("%d/%d\n",a[0],a[2]);
	return 0;
}
