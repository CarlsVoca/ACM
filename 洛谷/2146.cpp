#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

struct Edge{
    int u,v,nxt;
}e[maxn];

int nume=0,last[maxn];

inline void add_edge(int u,int v){
    e[++nume]=(Edge){u,v,last[u]};
    last[u]=nume;
}

namespace Tree_Chain_Division{
    int f[maxn],sz[maxn],son[maxn],dep[maxn],top[maxn],id[maxn],num=0;
    void dfs1(int u){
        sz[u]=1;
        for(int i=last[u];i;i=e[i].nxt){
            int v=e[i].v;
            dep[v]=dep[u]+1;
            dfs1(v);
            sz[u]+=sz[v];
            if(sz[v]>sz[son[u]])son[u]=v;
        }
    }
    void dfs2(int u,int tp){
        top[u]=tp;
        id[u]=++num;
        if(son[u])dfs2(son[u],tp);
        for(int i=last[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(v!=son[u])dfs2(v,v);
        }
    }
    namespace Segment_Tree{
        struct Node{
            int l,r,sum,lazy;
        }t[maxn<<2];
        void update(int k){
            t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
        }
        void build(int k,int l,int r){
            t[k].l=l;t[k].r=r;t[k].lazy=-1;
            if(l==r){
                t[k].sum=0;
                return;
            }
            int mid=l+r>>1;
            build(k<<1,l,mid);
            build(k<<1|1,mid+1,r);
            update(k);
        }
        void pushdown(int k){
            if(t[k].lazy==-1)return;
            t[k<<1].sum=t[k].lazy*(t[k<<1].r-t[k<<1].l+1);
            t[k<<1].lazy=t[k].lazy;
            t[k<<1|1].sum=t[k].lazy*(t[k<<1|1].r-t[k<<1|1].l+1);
            t[k<<1|1].lazy=t[k].lazy;
            t[k].lazy=-1;
        }
        void change_interval(int k,int L,int R,int x){
            if(t[k].l>R||t[k].r<L)return;
            if(t[k].l>=L&&t[k].r<=R){
                t[k].sum=x*(t[k].r-t[k].l+1);
                t[k].lazy=x;
                return;
            }
            pushdown(k);
            change_interval(k<<1,L,R,x);
            change_interval(k<<1|1,L,R,x);
            update(k);
        }
        int query_interval(int k,int L,int R){
            if(t[k].l>R||t[k].r<L)return 0;
            if(t[k].l>=L&&t[k].r<=R){
                return t[k].sum;
            }
            pushdown(k);
            return query_interval(k<<1,L,R)+query_interval(k<<1|1,L,R);
        }
    }
    using namespace Segment_Tree;
    void change_road(int u,int v,int x){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            change_interval(1,id[top[u]],id[u],x);
            u=f[top[u]];
        }
        if(dep[u]<dep[v])swap(u,v);
        change_interval(1,id[v],id[u],x);
    }
    int query_road(int u,int v){
        int res=0;
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            res+=query_interval(1,id[top[u]],id[u]);
            u=f[top[u]];
        }
        if(dep[u]<dep[v])swap(u,v);
        res+=query_interval(1,id[v],id[u]);    
        return res;
    }
    void change_root(int rt,int x){
        change_interval(1,id[rt],id[rt]+sz[rt]-1,x);
    }
    int query_root(int rt){
        return query_interval(1,id[rt],id[rt]+sz[rt]-1);
    }
}
using namespace Tree_Chain_Division;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,2,n){
        scanf("%d",&f[i]);f[i]++;
        add_edge(f[i],i);
    }
    dfs1(1);dfs2(1,1);build(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--){
        string s;
        int x;
        cin>>s>>x;x++;
        if(s=="install"){
            printf("%d\n",dep[x]+1-query_road(x,1));
            change_road(x,1,1);
        }
        else{
            printf("%d\n",query_root(x));
            change_root(x,0);
        }
    }
    return 0;
}