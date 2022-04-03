#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5005;

namespace Segment_Tree{
    struct Node{
        int l,r,sum,lazy;
    }t[maxn*4];
    inline void update(int k1){
        t[k1].sum=t[k1<<1].sum+t[k1<<1|1].sum;
    }
    void build(int k1,int l,int r){
        t[k1].l=l;t[k1].r=r;
        t[k1].lazy=t[k1].sum=0;
        if(l==r){
            t[k1].sum=0;
            return;
        }
        int mid=(l+r)>>1;
        build(k1<<1,l,mid);
        build(k1<<1|1,mid+1,r);
           update(k1);
    }
    inline void add(int k1){
        t[k1].sum+=t[k1>>1].lazy*(t[k1].r-t[k1].l+1);
        t[k1].lazy+=t[k1>>1].lazy;
    }
    inline void pushdown(int k1){
        add(k1<<1);
        add(k1<<1|1);
        t[k1].lazy=0;
    }
    void change_point(int k1,int pos,int k){
        if(pos>t[k1].r||pos<t[k1].l)return;
        if(t[k1].r==t[k1].l){
            t[k1].sum+=k;
            return;
        }
        pushdown(k1);
        change_point(k1<<1,pos,k);
        change_point(k1<<1|1,pos,k);
        update(k1);
    }
    void change_interval(int k1,int L,int R,int k){
        if(L>t[k1].r||R<t[k1].l)return;
        if(L<=t[k1].l&&R>=t[k1].r){
            t[k1].lazy+=k;
            t[k1].sum+=k*(t[k1].r-t[k1].l+1);
            return;
        }
        pushdown(k1);
        change_interval(k1<<1,L,R,k);
        change_interval(k1<<1|1,L,R,k);
        update(k1);
    }
    int query(int k1,int L,int R){
        if(L>t[k1].r||R<t[k1].l)return 0;
        if(L<=t[k1].l&&R>=t[k1].r){
            return t[k1].sum;
        }
        pushdown(k1);
        return query(k1<<1,L,R)+query(k1<<1|1,L,R);
    }
}
using namespace Segment_Tree;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        build(1,1,n);
        rep(i,1,n){
            if(a[i]!=1)
                change_interval(1,i+2,min(n,i+a[i]),1);
        }
        // printf("debug:");
        rep(i,1,n){
            if(query(1,i,i)>a[i]-1)change_interval(1,i+1,i+1,query(1,i,i)-a[i]+1);
        }
        // rep(i,1,n)printf("%d ",query(1,i,i));
        // putchar('\n');
        LL ans=0;
        rep(i,1,n)if(query(1,i,i)<a[i]-1)ans+=a[i]-1-query(1,i,i);
        printf("%lld\n",ans);
    }
    return 0;
}