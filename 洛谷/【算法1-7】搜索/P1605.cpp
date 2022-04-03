#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn=10;
const int dx[]={0,0,0,-1,1};
const int dy[]={0,1,-1,0,0};

bool a[maxn][maxn];
bool vis[maxn][maxn];

int ans;
int sx,sy,fx,fy;
int n,m,t;

void dfs(int x,int y)
{
	vis[x][y]=1;
	if(x==fx&&y==fy)ans++;
	else for(int i=1;i<=4;i++){
		if(!vis[x+dx[i]][y+dy[i]]&&x+dx[i]<=n&&x+dx[i]>=1&&y+dy[i]<=m&&y+dy[i]>=1&&!a[x+dx[i]][y+dy[i]]){
			dfs(x+dx[i],y+dy[i]);
		}
	}
	vis[x][y]=0;
}

int main()
{
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	int x,y;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		a[x][y]=1;
	}
	dfs(sx,sy);
	cout<<ans;
	return 0;
}