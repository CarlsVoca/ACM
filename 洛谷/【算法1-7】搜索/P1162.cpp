#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=35;
const int dx[]={0,0,0,-1,1};
const int dy[]={0,1,-1,0,0};

struct point{
	int x,y;
}d,b,c;
int n;
queue<point>q;

int a[maxn][maxn];

void bfs(int x,int y)
{
	d.x=x;
	d.y=y;
	q.push(d);
	while(!q.empty()){
		b=q.front();
		q.pop();
		a[b.x][b.y]=2;
		for(int i=1;i<=4;i++){
			int xx=b.x+dx[i];
			int yy=b.y+dy[i];
			if(xx>=1&&xx<=n&&yy<=n&&yy>=1&&!a[xx][yy]){
			  c.x=xx;
			  c.y=yy;
			  q.push(c);
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++){
	  	cin>>a[i][j];
	  }
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++){
	  	if(!a[i][j]&&(i==1||i==n||j==1||j==n)){
	  		bfs(i,j);
		}
	  }
	for(int i=1;i<=n;i++){
	  for(int j=1;j<=n;j++){
	  	if(a[i][j]==2)cout<<0<<" ";
	  	else if(a[i][j]==1)cout<<1<<" ";
	  	else cout<<2<<" ";
	  }
      cout<<endl;
	}
}
 