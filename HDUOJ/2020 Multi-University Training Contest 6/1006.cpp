#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
const int MOD=1e9+7;

int a[maxn],n,m;

struct Edge{
    int u,v;
    LL w;
    int nxt;
}e[maxn*2];

int nume=0,last[maxn];

inline void add_edge(int u,int v,LL w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

namespace Union_Find{
    int f[maxn],Rank[maxn];
    void Pre(){
        for(int i=1;i<=n;i++)f[i]=i,Rank[i]=0;
    }
    int Find(int x){
        return f[x]==x?x:f[x]=Find(f[x]);
    }
    void Union(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(fx!=fy){
            if(Rank[fx]>Rank[fy])f[fy]=fx;
            else{
                f[fx]=fy;
                if(Rank[fx]==Rank[fy])Rank[fy]++;
            }
        }
    }
}
using namespace Union_Find;

namespace Quick_Pow{
    LL do_main(LL a,int k){
        LL r=1,base=a;
        while(k){
            if(k&1)r=(r*base)%MOD;
            base=(base*base)%MOD;
            k>>=1;
        }
        return r%MOD;
    }
}
using namespace Quick_Pow;

int cnt0[maxn],cnt1[maxn];

void dfs1(int u,int f){
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f)continue;
        dfs1(v,u);
        cnt0[u]+=cnt0[v];
        cnt1[u]+=cnt1[v];
    }
    if(a[u]==0)cnt0[u]++;
    else cnt1[u]++;
}

LL ans=0;

void dfs2(int u,int f){
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==f)continue;
        dfs2(v,u);
        ans+=cnt0[v]*(cnt1[1]-cnt1[v])%MOD*e[i].w%MOD;
        ans+=cnt1[v]*(cnt0[1]-cnt0[v])%MOD*e[i].w%MOD;
        ans%=MOD;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d%d",&n,&m);
        nume=0;
        rep(i,1,n)last[i]=cnt0[i]=cnt1[i]=0;
        rep(i,1,n)scanf("%d",&a[i]);
        Pre();
        rep(i,1,m){
            int u,v;
            scanf("%d%d",&u,&v);
            if(Find(u)==Find(v))continue;
            else{
                add_edge(u,v,do_main(2,i));
                add_edge(v,u,do_main(2,i));
                Union(u,v);
            }
        }
        dfs1(1,1);
        dfs2(1,1);
        printf("%lld\n",ans);
    }
    return 0;
}