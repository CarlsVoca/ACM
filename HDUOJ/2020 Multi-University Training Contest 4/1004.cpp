#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=(1LL<<60);
const int maxn=1e5+5;
const int maxm=2e5+5;

namespace Fast_IO{
    LL read(){
        LL x=0;int flag=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;if(ch==EOF)return 0;ch=getchar();}
        while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
        return x*flag;
    }
}
using namespace Fast_IO;

struct Edge{
    int u,v;
    LL w;
    int nxt;
}e[maxm*8];

int nume=0,last[maxn*2];

inline void add_edge(int u,int v,LL w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

int n,m,ss,tt;
LL x;

/*
namespace SPFA{
    LL dis[maxn*2];
    bool vis[maxn*2];
    void do_main(int s){
        queue<int>q;
        memset(vis,0,sizeof(vis));
        rep(i,1,2*n)dis[i]=INF;
        vis[s]=1;
        dis[s]=0;
        q.push(s);
        while(!q.empty()){
            int u=q.front();q.pop();
            vis[u]=0;
            for(int i=last[u];i;i=e[i].nxt){
                int v=e[i].v;
                if(dis[v]>dis[u]+e[i].w){
                    dis[v]=dis[u]+e[i].w;
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
}
using namespace SPFA;
*/

namespace Dijkstra{
    typedef pair<LL,int> pii;
    LL dis[maxn*2];
    void do_main(int s){
        priority_queue< pii,vector<pii>,greater<pii> >q;
        rep(i,1,2*n)dis[i]=INF;
        dis[s]=0;
        q.push(pii(0LL,s));
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

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        nume=0;
        memset(last,0,sizeof(last));
        string s;
        scanf("%d%d%d%d%lld",&n,&m,&ss,&tt,&x);
        cin>>s;
        rep(i,1,m){
            int u,v;
            LL w;
            u=read();v=read();w=read();
            if(s[u-1]=='L'){
                if(s[v-1]=='L'){
                    add_edge(u*2-1,v*2-1,w);
                    add_edge(v*2-1,u*2-1,w);
                }
                else if(s[v-1]=='R'){
                    add_edge(u*2-1,v*2,w+x);
                    add_edge(v*2,u*2-1,w+x);
                }
                else if(s[v-1]=='M'){
                    add_edge(u*2-1,v*2-1,w);
                    add_edge(v*2-1,u*2-1,w);
                    add_edge(u*2-1,v*2,w+x);
                    add_edge(v*2,u*2-1,w+x);        
                }
            }
            if(s[u-1]=='R'){
                if(s[v-1]=='L'){
                    add_edge(u*2,v*2-1,w+x);
                    add_edge(v*2-1,u*2,w+x);
                }
                else if(s[v-1]=='R'){
                    add_edge(u*2,v*2,w);
                    add_edge(v*2,u*2,w);    
                }
                else if(s[v-1]=='M'){
                    add_edge(u*2,v*2-1,w+x);
                    add_edge(v*2-1,u*2,w+x);
                    add_edge(u*2,v*2,w);
                    add_edge(v*2,u*2,w);      
                }
            }
            if(s[u-1]=='M'){
                if(s[v-1]=='L'){
                    add_edge(u*2-1,v*2-1,w);
                    add_edge(v*2-1,u*2-1,w);
                    add_edge(u*2,v*2-1,w+x);
                    add_edge(v*2-1,u*2,w+x);
                }
                else if(s[v-1]=='R'){
                    add_edge(u*2-1,v*2,w+x);
                    add_edge(v*2,u*2-1,w+x);    
                    add_edge(u*2,v*2,w);
                    add_edge(v*2,u*2,w);
                }
                else if(s[v-1]=='M'){
                    add_edge(u*2-1,v*2-1,w);
                    add_edge(v*2-1,u*2-1,w);
                    add_edge(u*2,v*2-1,w+x);
                    add_edge(v*2-1,u*2,w+x);
                    add_edge(u*2-1,v*2,w+x);
                    add_edge(v*2,u*2-1,w+x);    
                    add_edge(u*2,v*2,w);
                    add_edge(v*2,u*2,w);        
                }
            }
        }
        if(s[ss-1]=='L'){
            do_main(ss*2-1);
            if(s[tt-1]=='L')printf("%lld\n",dis[tt*2-1]);
            else if(s[tt-1]=='R')printf("%lld\n",dis[tt*2]);
            else if(s[tt-1]=='M')printf("%lld\n",min(dis[tt*2-1],dis[tt*2]));
        }
        else if(s[ss-1]=='R'){
            do_main(ss*2);
            if(s[tt-1]=='L')printf("%lld\n",dis[tt*2-1]);
            else if(s[tt-1]=='R')printf("%lld\n",dis[tt*2]);
            else if(s[tt-1]=='M')printf("%lld\n",min(dis[tt*2-1],dis[tt*2]));
        }
        else if(s[ss-1]=='M'){
            LL ans=INF;
            do_main(ss*2);
            if(s[tt-1]=='L')ans=min(ans,dis[tt*2-1]);
            else if(s[tt-1]=='R')ans=min(ans,dis[tt*2]);
            else if(s[tt-1]=='M')ans=min(ans,min(dis[tt*2-1],dis[tt*2]));
            do_main(ss*2-1);
            if(s[tt-1]=='L')ans=min(ans,dis[tt*2-1]);
            else if(s[tt-1]=='R')ans=min(ans,dis[tt*2]);
            else if(s[tt-1]=='M')ans=min(ans,min(dis[tt*2-1],dis[tt*2]));
            printf("%lld\n",ans);
        }
    }
    return 0;
}