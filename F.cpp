#include<bits/stdc++.h>

const int maxn=1;
const int maxe=1;

struct Edge{
    int u,v,nxt;
}e[maxe];

int edge_id=0,head[maxn];
void add_edge(int u,int v){
    e[++edge_id]=(Edge){u,v,head[u]};
    head[u]=edge_id;
}
int main(){
int u;

for(int i=head[u];i;i=e[i].nxt){
    int v=e[i].v;
    /*
    ...
    */
}

}



namespace Floyd{
	void do_main(){
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
	}
}

int n;
int g[205][205];

int main(){

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }



}

namespace Dijkstra{
	typedef pair<int,int> pii;
	void do_main(int s){
		priority_queue< pii,vector<pii>,greater<pii> >q;
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		q.push(pii(0,s));
		while(!q.empty()){
			pii now=q.top();q.pop();
			int u=now.second;
			if(dis[u]<now.first)continue;
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dis[u]+e[i].w<dis[v]){
					dis[v]=dis[u]+e[i].w;
					q.push(pii(dis[v],v));
				}
			}
		}
	}
}


	int do_main(){
		Union_Find::pre();
		int cnt=0,ans=0;
		sort(e+1,e+nume+1);
		for(int i=1;i<=nume;i++){
			int fu=Union_Find::find(e[i].u),fv=Union_Find::find(e[i].v);
			if(fu!=fv){
				Union_Find::f[fu]=fv;
				ans+=e[i].w;
			}
		}
		return ans;
	}