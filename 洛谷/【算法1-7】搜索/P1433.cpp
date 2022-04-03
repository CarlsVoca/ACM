#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define INF 10000005

using namespace std;

const int maxn=17;

struct point{
	double x,y;
	bool vis;
}a[maxn];

double ans=INF;
int n;

void dfs(int k,int num,double w)
{
	if(w>=ans)return;
	if(num==n){
		ans=min(ans,w);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!a[i].vis){
			a[i].vis=1;
			dfs(i,num+1,w+sqrt((a[i].x-a[k].x)*(a[i].x-a[k].x)+(a[i].y-a[k].y)*(a[i].y-a[k].y)));
			a[i].vis=0;
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	dfs(0,0,0);
	printf("%.2f",ans);
	return 0;
}
