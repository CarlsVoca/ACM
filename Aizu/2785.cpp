#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

struct Data{
    LL a,b;
    bool operator < (const Data& d)const{
        return a-b>d.a-d.b;
    }
}d[maxn];

LL sum[maxn];

namespace Segment_Tree{
    struct Node{
        int l,r;
        LL sum,lazy;
    }t[maxn*4];
    inline void update(int k1){
        t[k1].sum=t[k1<<1].sum+t[k1<<1|1].sum;
    }
    void build(int k1,int l,int r){
        t[k1].l=l;t[k1].r=r;
        if(l==r){
            t[k1].sum=sum[l];
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
    void change_point(int k1,int pos,LL k){
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
    void change_interval(int k1,int L,int R,LL k){
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
    LL query(int k1,int L,int R){
        if(L>t[k1].r||R<t[k1].l)return 0;
        if(L<=t[k1].l&&R>=t[k1].r){
            return t[k1].sum;
        }
        pushdown(k1);
        return query(k1<<1,L,R)+query(k1<<1|1,L,R);
    }
}
using namespace Segment_Tree;

namespace Binary_Search{
    int do_main(int MIN,int MAX,LL k){
        int l=MIN,r=MAX;
        while(l<r){
            int mid=(l+r)/2;
            if(query(1,mid,mid)>=k)r=mid;
            else l=mid+1;
        }
        return query(1,l,l)>=k?l:INF;
    }
}
using namespace Binary_Search;

LL c[maxn],sumc[maxn];

int main(){
    int n;
    LL L;
    scanf("%d%lld",&n,&L);
    LL maxa=0;
    rep(i,1,n)scanf("%lld%lld",&d[i].a,&d[i].b),maxa=max(maxa,d[i].a);
    rep(i,1,n)scanf("%lld",&c[i]);
    rep(i,1,n)sumc[i]=sumc[i-1]+c[i];
    sort(d+1,d+n+1);
    if(maxa>=L){
        puts("1");
        return 0;
    }
    if(d[1].a-d[1].b==0||d[1].a-d[1].b<=c[1]){
        puts("-1");
        return 0;
    }
    rep(i,2,n)sum[i-1]=sum[i-2]+d[i].a-d[i].b;
    build(1,1,n-1);
    int ed=1;
    while(ed<n-1&&query(1,ed+1,ed+1)>sumc[ed+1]&&query(1,ed+1,ed+1)>query(1,ed,ed))ed++;
    int ans=INF;
    ans=min(do_main(1,ed,L-d[1].a)+1,ans);
    rep(i,2,n){
        change_interval(1,i-1,n-1,(d[i-1].a-d[i-1].b)-(d[i].a-d[i].b));
        while(ed<n-1&&query(1,ed+1,ed+1)>sumc[ed+1]&&query(1,ed+1,ed+1)>query(1,ed,ed))ed++;    
        ans=min(do_main(1,ed,L-d[i].a)+1,ans);
    }
    if(ans>=INF)puts("-1");
    else printf("%d\n",ans);
    return 0;
}