#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=(1LL<<60);
const int maxn=2005;
const int maxm=100005;

struct Edge{
    int u,v;
    double w;
    int nxt;
}e[maxm<<1];
int last[maxn],nume=0;

void add_edge(int u,int v,double w){
    e[++nume]=Edge{u,v,w,last[u]};
    last[u]=nume;
}

int n,m;

typedef pair<double,int> pii;
double dis[maxn];
void do_main(int s){
	priority_queue< pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[s]=1;
	q.push(pii(0,s));
	while(!q.empty()){
		pii now=q.top();q.pop();
		int u=now.second;
		if(dis[u]<now.first)continue;
		for(int i=last[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[u]*e[i].w<dis[v]){
				dis[v]=dis[u]*e[i].w;
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
        add_edge(u,v,100.0/(100-w));
        add_edge(v,u,100.0/(100-w));
    }
    int A,B;
    scanf("%d%d",&A,&B);
    do_main(B);
    printf("%.8lf\n",dis[A]*100);
    return 0;
}