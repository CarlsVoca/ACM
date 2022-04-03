#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=(1LL<<55);
const int maxn=5005;
const int maxm=100005;

struct Edge{
    int u,v,w,nxt;
}e[maxm<<1];
int last[maxn],nume=0;

void add_edge(int u,int v,int w){
    e[++nume]=Edge{u,v,w,last[u]};
    last[u]=nume;
}

int n,m;
typedef pair<LL,int> pii;
LL dis1[maxn],dis2[maxn];
void do_main(int s,LL dis[]){
	priority_queue< pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++)dis[i]=INF;
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

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    do_main(1,dis1);
    do_main(n,dis2);
    LL ans=INF;
    for(int i=1;i<=nume;i++){
        if(dis1[e[i].u]+dis2[e[i].v]+e[i].w>dis1[n]){
            ans=min(ans,dis1[e[i].u]+dis2[e[i].v]+e[i].w);
        }
    }
    printf("%lld\n",ans);
    return 0;
}