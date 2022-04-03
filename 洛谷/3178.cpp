#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;
const int maxe=maxn<<1;

struct Edge{
    int u,v,nxt;
}e[maxe];

int nume=0,last[maxn];

inline void add_edge(int u,int v){
    e[++nume]=(Edge){u,v,last[u]};
    last[u]=nume;
}

LL val[maxn];

namespace Tree_Chain_Division{
	int size[maxn],f[maxn],dep[maxn],son[maxn],top[maxn],id[maxn],real[maxn],num=0;
	void DFS_1(int u){
	    size[u]=1;
	    for(int i=last[u];i;i=e[i].nxt){
	        int v=e[i].v;
	        if(v!=f[u]){
	    	    f[v]=u;
	    	    dep[v]=dep[u]+1;
	    	    DFS_1(v);
	    	    size[u]+=size[v];
	    	    if(size[v]>size[son[u]])son[u]=v;
			}
		}
	}
	void DFS_2(int u,int tp){
	    top[u]=tp;
	    id[u]=++num;
	    real[num]=u;
	    if(son[u])DFS_2(son[u],tp);
	    for(int i=last[u];i;i=e[i].nxt){
	        int v=e[i].v;
	        if(v!=f[u]&&v!=son[u])DFS_2(v,v);
	    }
	}
	namespace Segment_Tree{
        struct Node{
            int l,r;
			LL sum,lazy;
        }t[maxn<<2];
        void update(int k){
            t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
        }
        void build(int k,int l,int r){
            t[k].l=l;t[k].r=r;t[k].lazy=0;
            if(l==r){
                t[k].sum=val[real[l]];
                return;
            }
            int mid=l+r>>1;
            build(k<<1,l,mid);
            build(k<<1|1,mid+1,r);
            update(k);
        }
        void pushdown(int k){
            if(t[k].lazy==0)return;
            t[k<<1].sum+=t[k].lazy*(t[k<<1].r-t[k<<1].l+1);
            t[k<<1].lazy+=t[k].lazy;
            t[k<<1|1].sum+=t[k].lazy*(t[k<<1|1].r-t[k<<1|1].l+1);
            t[k<<1|1].lazy+=t[k].lazy;
            t[k].lazy=0;
        }
        void change_interval(int k,int L,int R,LL x){
            if(t[k].l>R||t[k].r<L)return;
            if(t[k].l>=L&&t[k].r<=R){
                t[k].sum+=x*(t[k].r-t[k].l+1);
                t[k].lazy+=x;
                return;
            }
            pushdown(k);
            change_interval(k<<1,L,R,x);
            change_interval(k<<1|1,L,R,x);
            update(k);
        }
        LL query_interval(int k,int L,int R){
            if(t[k].l>R||t[k].r<L)return 0;
            if(t[k].l>=L&&t[k].r<=R){
                return t[k].sum;
            }
            pushdown(k);
            return query_interval(k<<1,L,R)+query_interval(k<<1|1,L,R);
        }
	}
	using namespace Segment_Tree;
    void init(int root){
        DFS_1(root);
        DFS_2(root,root);
        build(1,1,num);
    }
	void change_road(int u,int v,LL x){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            change_interval(1,id[top[u]],id[u],x);
            u=f[top[u]];
        }
        if(dep[u]<dep[v])swap(u,v);
        change_interval(1,id[v],id[u],x);
    }
	LL query_road(int u,int v){
        LL res=0;
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
        change_interval(1,id[rt],id[rt]+size[rt]-1,x);
    }
    LL query_root(int rt){
        return query_interval(1,id[rt],id[rt]+size[rt]-1);
    }
}
using namespace Tree_Chain_Division;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%lld",&val[i]);
    rep(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    init(1);
    while(m--){
        int k,x;
        LL a;
        scanf("%d",&k);
        if(k==1){
            scanf("%d%lld",&x,&a);
            change_road(x,x,a);
        }
        else if(k==2){
            scanf("%d%lld",&x,&a);
            change_root(x,a);
        }
        else{
            scanf("%d",&x);
            printf("%lld\n",query_road(x,1));
        }
    }
    return 0;
}