#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;
const int maxm=100005;

struct Edge{
    int u,v,w,nxt;
}e[maxm<<1];
int last[maxn],nume=0;

void add_edge(int u,int v,int w){
    e[++nume]=Edge{u,v,w,last[u]};
    last[u]=nume;
}

typedef pair<LL,int> pii;
LL dis[maxn];
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

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    do_main(1);
    printf("%lld\n",dis[n]);
    return 0;
}