#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn=405;
const int dx[]={0,-1,-2,-1,-2,1,2,1,2};
const int dy[]={0,-2,-1,2,1,-2,-1,2,1};

struct point{
	int x,y;
}nxt,now,pus;

bool vis[maxn][maxn];
int a[maxn][maxn];
int n,m,sx,sy;

queue < point > q;

void bfs(int x,int y)
{
	a[x][y]=0;
	now.x=x;
	now.y=y;
	q.push(now);
    while(!q.empty()){
    	nxt=q.front();
    	q.pop();
    	vis[nxt.x][nxt.y]=1;
    	for(int i=1;i<=8;i++){
    		int xx=nxt.x+dx[i];
    		int yy=nxt.y+dy[i];
    		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]){
    			a[xx][yy]=a[nxt.x][nxt.y]+1;
    			pus.x=xx;
    			pus.y=yy;
    			q.push(pus);
    			vis[xx][yy]=1;
			}
		}
	}
}

int main()
{
	memset(a,-1,sizeof(a));
	cin>>n>>m>>sx>>sy;
	bfs(sx,sy);
	for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++){
	  	printf("%-5d",a[i][j]);
	  }
	  cout<<endl;
    }
	return 0;
}
