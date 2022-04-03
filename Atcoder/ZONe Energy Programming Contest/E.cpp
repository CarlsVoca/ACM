#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=260000;

struct Edge{
	int u,v,nxt,w;
}e[maxn*305];
int last[maxn],nume=0;

void add_edge(int u,int v,int w){
	e[++nume]=(Edge){u,v,last[u],w};
	last[u]=nume;
}

namespace Dijkstra{
	typedef pair<int,int> pii;
	int dis[maxn];
	void do_main(int s){
		priority_queue< pii,vector<pii>,greater<pii> >q;
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		q.push(pii(0,s));
		while(!q.empty()){
			pii now=q.top();q.pop();
			int u=now.second;
			if(dis[u]<now.first)continue;
			for(int i=last[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dis[u]+e[i].w<dis[v]){
					dis[v]=dis[u]+e[i].w;
					q.push(pii(dis[v],v));
				}
			}
		}
	}
}
using namespace Dijkstra;

int n,m;

int id(int x,int y){
	return (x-1)*m+y;
}

int a[505][505],b[505][505];

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		rep(j,1,m-1){
			scanf("%d",&a[i][j]);
			add_edge(id(i,j),id(i,j+1),a[i][j]);
			add_edge(id(i,j+1),id(i,j),a[i][j]);
		}
	}
	rep(i,1,n-1){
		rep(j,1,m){
			scanf("%d",&b[i][j]);
			add_edge(id(i,j),id(i+1,j),b[i][j]);
		}
	}
	rep(i,2,n){
		rep(j,1,m){
			rep(k,1,i-1){
				add_edge(id(i,j),id(k,j),i-k+1);
			}
		}
	}
	do_main(1);
    printf("%d\n",dis[n*m]);
	return 0;
}