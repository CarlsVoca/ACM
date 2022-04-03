#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int a[maxn];

struct Node{
    int l,r,max;
}t[maxn*4];

inline void update(int k){
    t[k].max=max(t[k<<1].max,t[k<<1|1].max);
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    if(l==r){
        t[k].max=a[l];
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}

void change(int k,int pos,int val){
    if(pos>t[k].r||pos<t[k].l)return;
    if(t[k].l==t[k].r){
        t[k].max=val;
        return;
    }
    change(k<<1,pos,val);
    change(k<<1|1,pos,val);
    update(k);
}

int query(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return -INF;
    if(t[k].l>=L&&t[k].r<=R)return t[k].max;
    return max(query(k<<1,L,R),query(k<<1|1,L,R));
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        rep(i,1,n)scanf("%d",&a[i]);
        build(1,1,n);
        while(m--){
            char opt;
            int x,y;
            cin>>opt>>x>>y;
            if(opt=='Q')printf("%d\n",query(1,x,y));
            else change(1,x,y);
        }
    }
    return 0;
}