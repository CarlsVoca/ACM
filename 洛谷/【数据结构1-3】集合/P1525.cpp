#include<bits/stdc++.h>

using namespace std;

const int maxn=20005;
const int maxm=100005;

int n,m;
int en[maxn];

struct Data{
	int x,y,w;
	bool operator < (const Data &a)const{
		return w>a.w;
	}
}d[maxm];

namespace Union_Find_Set{
	int f[maxn];
	void pre(){
		for(int i=1;i<=n;i++)f[i]=i;
	}	
	int find(int x){
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void Union(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx!=fy)f[fx]=fy;
	}
}
using namespace Union_Find_Set;

int main()
{
	scanf("%d%d",&n,&m);
	pre();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].w);
	}
	sort(d+1,d+m+1);
	for(int i=1;i<=m;i++){
		if(find(d[i].x)==find(d[i].y)){
			printf("%d\n",d[i].w);
			return 0;
		}
		if(!en[d[i].x])en[d[i].x]=d[i].y;
		else Union(en[d[i].x],d[i].y);
		if(!en[d[i].y])en[d[i].y]=d[i].x;
		else Union(d[i].x,en[d[i].y]);
	}
	puts("0");
	return 0;
}