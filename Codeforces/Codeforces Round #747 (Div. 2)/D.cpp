#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;
const int maxe=5e5+5;

struct Edge{
    int u,v,w,nxt;
}e[maxe<<1];
int nume=0,last[maxn];

void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

bool vis[maxn];
int cnt=0;
bool flag=1;
int res[maxn];

void dfs(int u){
    // printf("%d %d\n",u,res[u]);
    vis[u]=1;
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(vis[v]){
            if(res[u]==1){
                if(res[v]!=e[i].w){
                    flag=0;
                    return;
                }
            }
            else{
                if(res[v]==e[i].w){
                    flag=0;
                    return;
                }
            }
            continue;
        }
        if(res[u]==1){
            res[v]=e[i].w;
        }
        else res[v]=(e[i].w^1);
        if(res[v]==0)cnt++;
        dfs(v);
    }
}

void turnn(int u,bool k){
    // printf("turnn:%d\n",u);
    vis[u]=k;
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(vis[v]==k)continue;
        turnn(v,k);
    }
}

string s;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int ans=0;
        nume=0;
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,n)last[i]=vis[i]=0;
        rep(i,1,m){
            int u,v,w;
            scanf("%d%d",&u,&v);
            cin>>s;
            if(s=="imposter")w=0;
            else w=1;
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        // puts("test");
        bool impos=0;
        rep(i,1,n){
            if(!vis[i]){
                int tmp=-1;
                cnt=0;flag=1;
                res[i]=0;cnt++;
                dfs(i);
                if(flag)tmp=max(tmp,cnt);
                turnn(i,0);
                // rep(i,1,3)printf("vis[%d]=%d\n",i,vis[i]);
                // puts("deu");
                cnt=0;flag=1;
                res[i]=1;
                dfs(i);
                if(flag)tmp=max(tmp,cnt);
                if(tmp==-1){
                    impos=1;
                    break;
                }
                ans+=tmp;
            }
        }
        if(impos)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}