#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=100000000000LL;
const int maxn=100005;

struct Data{
    LL a;
    int pos;
    bool operator < (const Data& d)const{
        return a<d.a;
    }
    bool operator > (const Data& d)const{
        return a>d.a;
    }
    bool operator == (const Data& d)const{
        return a==d.a;
    }
}d[maxn];

int sz,l[maxn],r[maxn];
LL tag[maxn];

int judge(int x){
    return (x-1)/sz+1;
}

void modify(int L,int R,LL x){
    int bl=judge(L),br=judge(R);
    // printf("debug:%d %d\n",bl,br);
    if(bl==br){
        rep(i,l[bl],r[bl]){
            if(d[i].pos>=L&&d[i].pos<=R)d[i].a+=x;
        }
        sort(d+l[bl],d+r[bl]+1);
        return;
    }
    rep(i,l[bl],r[bl]){
        if(d[i].pos>=L)d[i].a+=x;
    }
    sort(d+l[bl],d+r[bl]+1);
    rep(i,l[br],r[br]){
        if(d[i].pos<=R)d[i].a+=x;
    }
    sort(d+l[br],d+r[br]+1);
    rep(i,bl+1,br-1)tag[i]+=x;
}

LL query_pre(int L,int R,int x){
    LL res=-INF;
    int bl=judge(L),br=judge(R);
    // printf("debug:%d %d\n",bl,br);
    if(bl==br){
        rep(i,l[bl],r[bl]){
            if(d[i].pos>=L&&d[i].pos<=R&&d[i].a+tag[bl]<x)res=max(res,d[i].a+tag[bl]);
        }
        return res==-INF?-1:res;
    }
    rep(i,l[bl],r[bl]){
        if(d[i].pos>=L&&d[i].a+tag[bl]<x)res=max(res,d[i].a+tag[bl]);
    }
    rep(i,l[br],r[br]){
        if(d[i].pos<=R&&d[i].a+tag[br]<x)res=max(res,d[i].a+tag[br]);
    }
    rep(i,bl+1,br-1){
        int pos=lower_bound(d+l[i],d+r[i]+1,Data{x-tag[i],0})-d-1;
        if(d[pos].a+tag[i]<x)res=max(res,d[pos].a+tag[i]);
    }
    return res==-INF?-1:res;
}

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%lld",&d[i].a),d[i].pos=i;
    sz=sqrt(n);
    int cnt=0;
    for(int i=1;i<=n;i+=sz){
        l[++cnt]=i;
        if(i+sz-1<=n)r[cnt]=i+sz-1;
        else r[cnt]=n;
    }
    rep(i,1,cnt)sort(d+l[i],d+r[i]+1);
    rep(T,1,n){
        int opt,L,R;
        LL c;
        scanf("%d%d%d%lld",&opt,&L,&R,&c);
        if(opt==0)modify(L,R,c);
        else printf("%lld\n",query_pre(L,R,c));
    }
    return 0;
}