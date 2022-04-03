#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long f[30][30];
bool vis[30][30]; 
long long a,b,c,d;
int main()
{
	scanf("%lld%lld%lld%lld",&c,&d,&a,&b);
	a+=5;b+=5;c+=5;d+=5;
	vis[a][b]=1;
	vis[a-2][b+1]=1;
	vis[a-2][b-1]=1;
	vis[a+2][b+1]=1;
	vis[a+2][b-1]=1;
	vis[a-1][b+2]=1;
	vis[a-1][b-2]=1;
	vis[a+1][b+2]=1;
	vis[a+1][b-2]=1; 
    f[5][5]=1;
	for(int i=5;i<=c;i++)
      for(int j=5;j<=d;j++)
      {
        if(i==5&&j==5)
          continue;
		if(!vis[i][j])
          f[i][j]=f[i-1][j]+f[i][j-1];
        //printf("%d %d %d\n",i,j,f[i][j]);
	  }
	printf("%lld",f[c][d]);
	return 0;
}


