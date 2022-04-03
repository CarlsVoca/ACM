#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=305;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

struct Edge{
    int u,v,w,nxt;
}e[maxn*maxn*4];

int nume=0,last[maxn*maxn];

inline void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

namespace Dijkstra{
    typedef pair<int,int> pii;
    int dis[maxn*maxn];
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

char s[maxn][maxn];
int n,m;
int p[maxn][maxn];

int id(int x,int y){return (x-1)*m+y;}

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%s",s[i]+1);
    int sx,sy,tx,ty;
    rep(i,1,n)
        rep(j,1,m){
            if(s[i][j]=='@')sx=i,sy=j;
            else if(s[i][j]=='=')tx=i,ty=j;
            else if(!p[i][j]&&s[i][j]>='A'&&s[i][j]<='Z'){
                rep(a,1,n)
                    rep(b,1,m){
                        if(a==i&&b==j)continue;
                        if(s[a][b]==s[i][j]){
                            p[i][j]=id(a,b);
                            p[a][b]=id(i,j);
                        }
                    }
            }
        }
    rep(i,1,n)
        rep(j,1,m){
            if(s[i][j]=='#')continue;
            rep(k,0,3){
                int x=i+dx[k],y=j+dy[k];
                if(x>=1&&x<=n&&y>=1&&y<=m){
                    if(s[x][y]=='#')continue;
                    else if(s[x][y]=='.'||s[x][y]=='@'||s[x][y]=='='){
                        add_edge(id(i,j),id(x,y),1);
                    }
                    else if(s[x][y]>='A'&&s[x][y]<='Z'){
                        if(p[x][y]){
                            add_edge(id(i,j),p[x][y],1);
                        }
                        else add_edge(id(i,j),id(x,y),1);
                    }
                }
            }
        }
    do_main(id(sx,sy));
    printf("%d\n",dis[id(tx,ty)]);
    return 0;
}