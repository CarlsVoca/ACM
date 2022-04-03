#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

char mp[maxn][maxn];
int idx[maxn][maxn];
int cnt;
int n,m;

void dfs(int x,int y,int num)
{
	idx[x][y]=num;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++){
			if(!(i==0&&j==0))
				if(!(x<1||x>n||y<1||y>m))
					if(!idx[x+i][y+j]&&mp[x+i][y+j]=='W')
						dfs(x+i,y+j,num);
		}
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(idx,0,sizeof(idx));
	cnt=0;
	for(int i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!idx[i][j]&&mp[i][j]=='W')dfs(i,j,++cnt);
		}
	printf("%d\n",cnt);
	return 0;
}