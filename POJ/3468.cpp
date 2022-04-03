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
const int maxn=100005;

int a[maxn];

struct Node{
    int l,r;
    LL sum,lazy;
}t[maxn<<2];

void update(int k){
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lazy=0;
    if(l==r){
        t[k].sum=a[l];
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}

void pushdown(int k){
    t[k<<1].lazy+=t[k].lazy;    
    t[k<<1].sum+=t[k].lazy*(t[k<<1].r-t[k<<1].l+1);
    t[k<<1|1].lazy+=t[k].lazy;    
    t[k<<1|1].sum+=t[k].lazy*(t[k<<1|1].r-t[k<<1|1].l+1);
    t[k].lazy=0;
}

void change(int k,int L,int R,int val){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].lazy+=val;
        t[k].sum+=(t[k].r-t[k].l+1)*val;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,val);
    change(k<<1|1,L,R,val);
    update(k);
}

LL query(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return 0;
    if(t[k].l>=L&&t[k].r<=R)return t[k].sum;
    pushdown(k);
    return query(k<<1,L,R)+query(k<<1|1,L,R);
}

int main(){
    int n,Q;
    scanf("%d%d",&n,&Q);
    rep(i,1,n)scanf("%d",&a[i]);
    build(1,1,n);
    rep(i,1,Q){
        char opt;
        int x,y,z;
        cin>>opt;
        if(opt=='Q'){
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,x,y));
        }
        else{
            scanf("%d%d%d",&x,&y,&z);
            change(1,x,y,z);
        }
    }
    return 0;
}