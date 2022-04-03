#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10005;

struct Node{
    int l,r,c,lazy;
}t[maxn<<3];

void pushdown(int k){
    t[k<<1].lazy=max(t[k<<1].lazy,t[k].lazy);
    t[k<<1].c=max(t[k<<1].c,t[k].lazy);
    t[k<<1|1].lazy=max(t[k<<1|1].lazy,t[k].lazy);
    t[k<<1|1].c=max(t[k<<1|1].c,t[k].lazy);
    t[k].lazy=0;
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lazy=0;
    if(l==r){
        t[k].c=0;
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void change(int k,int L,int R,int val){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].c=val;
        t[k].lazy=val;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,val);
    change(k<<1|1,L,R,val);
}

int query(int k,int pos){
    if(t[k].l>pos||t[k].r<pos)return 0;
    if(t[k].l==t[k].r)return t[k].c;
    pushdown(k);
    return max(query(k<<1,pos),query(k<<1|1,pos));
}

int l[maxn],r[maxn];

int T[maxn<<1],n,m;
void lisan(){
    rep(i,1,n)T[i]=l[i],T[i+n]=r[i];
    sort(T+1,T+2*n+1);
    m=unique(T+1,T+2*n+1)-T-1;
    rep(i,1,n)l[i]=lower_bound(T+1,T+m+1,l[i])-T,r[i]=lower_bound(T+1,T+m+1,r[i])-T;
}

bool vis[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n)vis[i]=0;
        rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
        lisan();
        build(1,1,m);
        rep(i,1,n)change(1,l[i],r[i],i);
        rep(i,1,m)vis[query(1,i)]=1;
        int ans=0;
        rep(i,1,n)if(vis[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}