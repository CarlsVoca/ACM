#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,LL> pil;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;

const LL INF=(1LL<<50);
const int maxn=1e5+5;
const int maxe=2e5+5;

struct Edge{
    int u,v,a,b,nxt;
}e[maxe];
int nume=0,last[maxn];
void add_edge(int u,int v,int a,int b){
    e[++nume]=(Edge){u,v,a,b,last[u]};
    last[u]=nume;
}

map<int,LL> dp[maxn];

bool minn(LL &a,LL b){
    if(b<a){a=b;return 1;}
    return 0;
}

LL dis[maxn];
// priority_queue< pli,vector<pli>,greater<pli> > q;
queue<int> q;
bool vis[maxn];

void update(int u){
    vector<pil> in;
    vector<pii> out;
    for(auto it=dp[u].begin();it!=dp[u].end();++it){
        in.push_back(pil(e[it->first].a,it->second));
    }
    for(int i=last[u];i;i=e[i].nxt){
        out.push_back(pii(e[i].a,i));
    }
    sort(in.begin(),in.end());
    sort(out.begin(),out.end());
    int j=0;
    LL MIN=INF;
    rep(i,0,(int)out.size()-1){
        while(j<(int)in.size()&&in[j].first<out[i].first){
            MIN=min(MIN,in[j].second);
            j++;
        }
        if(!dp[e[out[i].second].v].count(out[i].second))dp[e[out[i].second].v][out[i].second]=INF;
        if(minn(dp[e[out[i].second].v][out[i].second],MIN+e[out[i].second].a-e[out[i].second].b)&&!vis[e[out[i].second].v]){
            q.push(e[out[i].second].v);
            vis[e[out[i].second].v]=1;
        }
    }
    sort(in.begin(),in.end(),greater<pil>());
    sort(out.begin(),out.end(),greater<pii>());
    j=0;
    MIN=INF;
    rep(i,0,(int)out.size()-1){
        while(j<(int)in.size()&&in[j].first>=out[i].first){
            MIN=min(MIN,in[j].second);
            j++;
        }
        if(minn(dp[e[out[i].second].v][out[i].second],MIN+e[out[i].second].a)&&!vis[e[out[i].second].v]){
            q.push(e[out[i].second].v);
            vis[e[out[i].second].v]=1;
        }
        // if(minn(dis[e[out[i].second].v],dp[e[out[i].second].v][out[i].second])&&flag)q.push(pli(dis[e[out[i].second].v],e[out[i].second].v));
        if(minn(dis[e[out[i].second].v],dp[e[out[i].second].v][out[i].second])&&!vis[e[out[i].second].v]){
            q.push(e[out[i].second].v);
            vis[e[out[i].second].v]=1;
        }
    }
}

int n,m;

// namespace Dijkstra{
// 	void do_main(int s){
//         while(!q.empty())q.pop();
// 		rep(i,1,n)dis[i]=INF;
// 		dis[s]=0;
// 		queue<pli> tmp;
//         for(int i=last[s];i;i=e[i].nxt){
//             int v=e[i].v;
//             dp[v][i]=e[i].a;
//             if(minn(dis[v],dp[v][i])){
//                 q.push(pli(dis[v],v));
//                 tmp.push(pli(dis[v],v));
//             }
//         }
//         while(!tmp.empty()){
//         	pli now=tmp.front();tmp.pop();
// 			int u=now.second;
// 			if(dis[u]<now.first)continue;
// 			update(u,0);
// 		}
//         q.push(pli(0LL,s));
// 		while(!q.empty()){
// 			pli now=q.top();q.pop();
// 			int u=now.second;
// 			if(dis[u]<now.first)continue;
// 			update(u,1);
// 		}
// 	}
// }
// using namespace Dijkstra;

namespace SPFA{
	void do_main(int s){
		memset(vis,0,sizeof(vis));
        rep(i,1,n)dis[i]=INF;
		dis[s]=0;
        for(int i=last[s];i;i=e[i].nxt){
            int v=e[i].v;
            dp[v][i]=e[i].a;
            if(minn(dis[v],dp[v][i])){
                q.push(v);
                vis[v]=1;
            }
        }
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=0;
			update(u);
		}
	}
}
using namespace SPFA;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        nume=0;
        rep(i,1,n){
            last[i]=0;
            dp[i].clear();
        }
        rep(i,1,m){
            int u,v,a,b;
            scanf("%d%d%d%d",&u,&v,&a,&b);
            add_edge(u,v,a,b);
        }
        do_main(1);
        rep(i,1,n-1)printf("%lld ",dis[i]>=INF?-1:dis[i]);
        printf("%lld\n",dis[n]>=INF?-1:dis[n]);
    }
    return 0;
}