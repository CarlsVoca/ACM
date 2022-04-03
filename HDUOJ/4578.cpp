#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;
const int MOD=10007;

struct Node{
    int l,r;
    LL sum[4],lazy[4];
}t[maxn<<3];

void update(int k){
    rep(i,1,3)t[k].sum[i]=(t[k<<1].sum[i]+t[k<<1|1].sum[i])%MOD;
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    rep(i,1,3){
        t[k].lazy[i]=-1;
        t[k].sum[i]=0;
    }
    if(l==r)return;
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void pushdown(int k){
    if(t[k].lazy[3]!=-1){
        LL c=t[k].lazy[3];
        t[k<<1].sum[1]=c*(t[k<<1].r-t[k<<1].l+1)%MOD;
        t[k<<1].sum[2]=c*c%MOD*(t[k<<1].r-t[k<<1].l+1)%MOD;
        t[k<<1].sum[3]=c*c%MOD*c%MOD*(t[k<<1].r-t[k<<1].l+1)%MOD;
        t[k<<1].lazy[3]=c;t[k<<1].lazy[1]=t[k<<1].lazy[2]=-1;
        t[k<<1|1].sum[1]=c*(t[k<<1|1].r-t[k<<1|1].l+1)%MOD;
        t[k<<1|1].sum[2]=c*c%MOD*(t[k<<1|1].r-t[k<<1|1].l+1)%MOD;
        t[k<<1|1].sum[3]=c*c%MOD*c%MOD*(t[k<<1|1].r-t[k<<1|1].l+1)%MOD;
        t[k<<1|1].lazy[3]=c;t[k<<1|1].lazy[1]=t[k<<1|1].lazy[2]=-1;
        t[k].lazy[3]=-1;
    }
    if(t[k].lazy[2]!=-1){
        LL c=t[k].lazy[2];
        t[k<<1].sum[1]=t[k<<1].sum[1]*c%MOD;
        t[k<<1].sum[2]=t[k<<1].sum[2]*c%MOD*c%MOD;
        t[k<<1].sum[3]=t[k<<1].sum[3]*c%MOD*c%MOD*c%MOD;
        if(t[k<<1].lazy[2]!=-1)t[k<<1].lazy[2]=t[k<<1].lazy[2]*c%MOD;
        else t[k<<1].lazy[2]=c;
        if(t[k<<1].lazy[1]!=-1)t[k<<1].lazy[1]=t[k<<1].lazy[1]*c%MOD;
        t[k<<1|1].sum[1]=t[k<<1|1].sum[1]*c%MOD;
        t[k<<1|1].sum[2]=t[k<<1|1].sum[2]*c%MOD*c%MOD;
        t[k<<1|1].sum[3]=t[k<<1|1].sum[3]*c%MOD*c%MOD*c%MOD;
        if(t[k<<1|1].lazy[2]!=-1)t[k<<1|1].lazy[2]=t[k<<1|1].lazy[2]*c%MOD;
        else t[k<<1|1].lazy[2]=c;
        if(t[k<<1|1].lazy[1]!=-1)t[k<<1|1].lazy[1]=t[k<<1|1].lazy[1]*c%MOD;
        t[k].lazy[2]=-1;
    }
    if(t[k].lazy[1]!=-1){
        LL c=t[k].lazy[1];
        t[k<<1].sum[3]+=((t[k<<1].r-t[k<<1].l+1)*c%MOD*c%MOD*c%MOD+3*c%MOD*(t[k<<1].sum[2]+t[k<<1].sum[1]*c%MOD))%MOD;
        t[k<<1].sum[2]+=((t[k<<1].r-t[k<<1].l+1)*c%MOD*c%MOD+2*t[k<<1].sum[1]%MOD*c%MOD)%MOD;
        t[k<<1].sum[1]+=(c*(t[k<<1].r-t[k<<1].l+1))%MOD;
        if(t[k<<1].lazy[1]!=-1)t[k<<1].lazy[1]+=c;
        else t[k<<1].lazy[1]=c;
        rep(i,1,3)t[k<<1].sum[i]%=MOD;
        t[k<<1].lazy[1]%=MOD;
        t[k<<1|1].sum[3]+=(t[k<<1|1].r-t[k<<1|1].l+1)*c%MOD*c%MOD*c%MOD+3*c%MOD*(t[k<<1|1].sum[2]+t[k<<1|1].sum[1]*c%MOD)%MOD;
        t[k<<1|1].sum[2]+=(t[k<<1|1].r-t[k<<1|1].l+1)*c%MOD*c%MOD+2*t[k<<1|1].sum[1]%MOD*c%MOD;
        t[k<<1|1].sum[1]+=c*(t[k<<1|1].r-t[k<<1|1].l+1)%MOD;
        if(t[k<<1|1].lazy[1]!=-1)t[k<<1|1].lazy[1]+=c;
        else t[k<<1|1].lazy[1]=c;
        rep(i,1,3)t[k<<1|1].sum[i]%=MOD;
        t[k<<1|1].lazy[1]%=MOD;
        t[k].lazy[1]=-1;
    }
}

void change(int k,int L,int R,int tp,LL c){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        pushdown(k);
        t[k].lazy[tp]=c;
        if(tp==1){
            t[k].sum[3]+=(t[k].r-t[k].l+1)*c%MOD*c%MOD*c%MOD+3*c%MOD*(t[k].sum[2]+t[k].sum[1]*c%MOD)%MOD;
            t[k].sum[2]+=(t[k].r-t[k].l+1)*c%MOD*c%MOD+2*t[k].sum[1]*c;
            t[k].sum[1]+=c*(t[k].r-t[k].l+1)%MOD;
            rep(i,1,3)t[k].sum[i]%=MOD;
        }
        else if(tp==2){
            t[k].sum[1]*=c;
            t[k].sum[2]*=c*c%MOD;
            t[k].sum[3]*=c*c%MOD*c%MOD;
            rep(i,1,3)t[k].sum[i]%=MOD;
        }
        else{
            t[k].sum[1]=c*(t[k].r-t[k].l+1)%MOD;
            t[k].sum[2]=c*c%MOD*(t[k].r-t[k].l+1)%MOD;
            t[k].sum[3]=c*c%MOD*c%MOD*(t[k].r-t[k].l+1)%MOD;
            rep(i,1,3)t[k].sum[i]%=MOD;
        }
        return;
    }
    pushdown(k);
    change(k<<1,L,R,tp,c);
    change(k<<1|1,L,R,tp,c);
    update(k);
}

LL query(int k,int L,int R,int p){
    if(t[k].l>R||t[k].r<L)return 0;
    if(t[k].l>=L&&t[k].r<=R)return t[k].sum[p];
    pushdown(k);
    return (query(k<<1,L,R,p)+query(k<<1|1,L,R,p))%MOD;
}

int main(){
    // freopen("4578.in","r",stdin);
    // freopen("4578.out","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0&&m==0)break;
        build(1,1,n);
        rep(i,1,m){
            int op,x,y;
            LL c;
            scanf("%d%d%d%lld",&op,&x,&y,&c);
            if(op!=4)change(1,x,y,op,c);
            else printf("%lld\n",query(1,x,y,c));
        }
    }
    return 0;
}