#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=1ll<<60;
const int maxn=1005;

LL a[maxn][maxn],dp[maxn][maxn],sum[maxn][maxn];

struct Node{
    int l,r;
    LL max,lazy;
}t[maxn<<2];

void update(int k){
    t[k].max=max(t[k<<1].max,t[k<<1|1].max);
}

void build(int c,int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].max=-INF;
    t[k].lazy=0;
    if(l==r){t[k].max=dp[l][c-1]+sum[l][c];return;}
    int mid=l+r>>1;
    build(c,k<<1,l,mid);
    build(c,k<<1|1,mid+1,r);
    update(k);
}

void pushdown(int k){
    t[k<<1].lazy+=t[k].lazy;
    t[k<<1|1].lazy+=t[k].lazy;
    t[k<<1].max+=t[k].lazy;
    t[k<<1|1].max+=t[k].lazy;
    t[k].lazy=0;
}

void change(int k,int L,int R,LL x){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].lazy+=x;
        t[k].max+=x;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,x);
    change(k<<1|1,L,R,x);
    update(k);
}

LL query(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return -INF;
    if(t[k].l>=L&&t[k].r<=R)return t[k].max;
    pushdown(k);
    return max(query(k<<1,L,R),query(k<<1|1,L,R));
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)rep(j,1,m)scanf("%lld",&a[i][j]);
    rep(j,1,m)rep(i,1,n)sum[i][j]=sum[i-1][j]+a[i][j];
    rep(i,1,n)dp[i][1]=dp[i-1][1]+a[i][1];
    rep(j,2,m){
        build(j,1,1,n);
        rep(i,1,n){
            dp[i][j]=query(1,1,n);
            change(1,1,i,a[i+1][j]);
            change(1,i+1,n,-a[i][j]);
        }
    }
    printf("%lld\n",dp[n][m]);
    return 0;
}