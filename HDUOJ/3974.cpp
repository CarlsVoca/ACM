#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5e4+5;

struct Node{
    int l,r,lazy,c;
}t[maxn<<2];

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lazy=-1;t[k].c=-1;
    if(l==r)return;
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void pushdown(int k){
    if(t[k].lazy==-1)return;
    t[k<<1].c=t[k<<1].lazy=t[k].lazy;
    t[k<<1|1].c=t[k<<1|1].lazy=t[k].lazy;
    t[k].lazy=-1;
}

void change(int k,int L,int R,int c){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].c=c;
        t[k].lazy=c;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,c);
    change(k<<1|1,L,R,c);
}

int query(int k,int x){
    if(t[k].l>x||t[k].r<x)return 0;
    if(t[k].l==t[k].r)return t[k].c;
    pushdown(k);
    return query(k<<1,x)^query(k<<1|1,x);
}

struct Edge{
    int u,v,w,nxt;
}e[maxn];

int nume=0,last[maxn];

inline void add_edge(int u,int v,int w){
    e[++nume]=(Edge){u,v,w,last[u]};
    last[u]=nume;
}

int du[maxn];
int d[maxn],cnt=0,pos[maxn],l[maxn],r[maxn];

void dfs(int u){
    d[++cnt]=u;pos[u]=cnt;
    l[u]=cnt;
    for(int i=last[u];i;i=e[i].nxt){
        int v=e[i].v;
        dfs(v);
    }
    r[u]=cnt;
}

int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",++cas);
        cnt=nume=0;
        int n;
        scanf("%d",&n);
        rep(i,1,n)du[i]=0,last[i]=0;
        rep(i,1,n-1){
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(v,u,1);
            du[u]++;
        }
        int root=0;
        rep(i,1,n){
            if(!du[i]){
                root=i;
                break;
            }
        }
        dfs(root);
        build(1,1,n);
        int m;
        scanf("%d",&m);
        rep(i,1,m){
            char opt;
            int x,y;
            cin>>opt;
            if(opt=='C'){
                scanf("%d",&x);
                printf("%d\n",query(1,pos[x]));
            }
            else{
                scanf("%d%d",&x,&y);
                change(1,l[x],r[x],y);
            }
        }
    }
    return 0;
}