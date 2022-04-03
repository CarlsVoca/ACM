#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long LL;

LL f[25][25][25];

LL w(LL a,LL b,LL c)
{
	if(a>0&&b>0&&c>0&&a<=20&&b<=20&&c<=20&&f[a][b][c]!=-0x7f)return f[a][b][c];
	if(a<=0||b<=0||c<=0)return 1;
	else if(a>20||b>20||c>20)return w(20,20,20);
	else if(a<b&&b<c)return f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	return f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main()
{
	LL a,b,c;
	for(int i=1;i<=20;i++)
	  for(int j=1;j<=20;j++)
	    for(int k=1;k<=20;k++){
	    	f[i][j][k]=-0x7f;
		}
	while(scanf("%lld%lld%lld",&a,&b,&c)==3&&!(a==-1&&b==-1&&c==-1))
	  printf("w(%lld, %lld, %lld) = %d\n",a,b,c,w(a,b,c));
	return 0;
}


