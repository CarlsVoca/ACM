#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;
int MOD=10007;

LL a[maxn];

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
    if(l==r){
        t[k].sum[1]=a[l];
        t[k].sum[2]=a[l]*a[l]%MOD;
        t[k].sum[3]=a[l]*a[l]%MOD*a[l]%MOD;
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}

void pushdown(int k){
    if(t[k].lazy[3]!=-1){
        LL c=t[k].lazy[3];
        t[k<<1].sum[1]=c*(t[k<<1].r-t[k<<1].l+1)%MOD;
        t[k<<1].sum[2]=c*c*(t[k<<1].r-t[k<<1].l+1)%MOD;
        t[k<<1].sum[3]=c*c*c*(t[k<<1].r-t[k<<1].l+1)%MOD;
        t[k<<1].lazy[3]=c;t[k<<1].lazy[1]=t[k<<1].lazy[2]=-1;
        t[k<<1|1].sum[1]=c*(t[k<<1|1].r-t[k<<1|1].l+1)%MOD;
        t[k<<1|1].sum[2]=c*c*(t[k<<1|1].r-t[k<<1|1].l+1)%MOD;
        t[k<<1|1].sum[3]=c*c*c*(t[k<<1|1].r-t[k<<1|1].l+1)%MOD;
        t[k<<1|1].lazy[3]=c;t[k<<1|1].lazy[1]=t[k<<1|1].lazy[2]=-1;
        t[k].lazy[3]=-1;
    }
    if(t[k].lazy[2]!=-1){
        LL c=t[k].lazy[2];
        t[k<<1].sum[1]=t[k<<1].sum[1]*c%MOD;
        t[k<<1].sum[2]=t[k<<1].sum[2]*c*c%MOD;
        t[k<<1].sum[3]=t[k<<1].sum[3]*c*c*c%MOD;
        if(t[k<<1].lazy[2]!=-1)t[k<<1].lazy[2]=t[k<<1].lazy[2]*c%MOD;
        else t[k<<1].lazy[2]=c;
        if(t[k<<1].lazy[1]!=-1)t[k<<1].lazy[1]=t[k<<1].lazy[1]*c%MOD;
        t[k<<1|1].sum[1]=t[k<<1|1].sum[1]*c%MOD;
        t[k<<1|1].sum[2]=t[k<<1|1].sum[2]*c*c%MOD;
        t[k<<1|1].sum[3]=t[k<<1|1].sum[3]*c*c*c%MOD;
        if(t[k<<1|1].lazy[2]!=-1)t[k<<1|1].lazy[2]=t[k<<1|1].lazy[2]*c%MOD;
        else t[k<<1|1].lazy[2]=c;
        if(t[k<<1|1].lazy[1]!=-1)t[k<<1|1].lazy[1]=t[k<<1|1].lazy[1]*c%MOD;
        t[k].lazy[2]=-1;
    }
    if(t[k].lazy[1]!=-1){
        LL c=t[k].lazy[1];
        t[k<<1].sum[3]+=((t[k<<1].r-t[k<<1].l+1)*c*c*c+3*c*(t[k<<1].sum[2]+t[k<<1].sum[1]*c));
        t[k<<1].sum[2]+=((t[k<<1].r-t[k<<1].l+1)*c*c+2*t[k<<1].sum[1]*c);
        t[k<<1].sum[1]+=(c*(t[k<<1].r-t[k<<1].l+1));
        if(t[k<<1].lazy[1]!=-1)t[k<<1].lazy[1]+=c;
        else t[k<<1].lazy[1]=c;
        rep(i,1,3)t[k<<1].sum[i]%=MOD;
        t[k<<1].lazy[1]%=MOD;
        t[k<<1|1].sum[3]+=(t[k<<1|1].r-t[k<<1|1].l+1)*c*c*c+3*c*(t[k<<1|1].sum[2]+t[k<<1|1].sum[1]*c);
        t[k<<1|1].sum[2]+=(t[k<<1|1].r-t[k<<1|1].l+1)*c*c+2*t[k<<1|1].sum[1]*c;
        t[k<<1|1].sum[1]+=c*(t[k<<1|1].r-t[k<<1|1].l+1);
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
            t[k].sum[3]+=(t[k].r-t[k].l+1)*c*c*c+3*c*(t[k].sum[2]+t[k].sum[1]*c);
            t[k].sum[2]+=(t[k].r-t[k].l+1)*c*c+2*t[k].sum[1]*c;
            t[k].sum[1]+=c*(t[k].r-t[k].l+1);
            rep(i,1,3)t[k].sum[i]%=MOD;
        }
        else if(tp==2){
            t[k].sum[1]*=c;
            t[k].sum[2]*=c*c;
            t[k].sum[3]*=c*c*c;
            rep(i,1,3)t[k].sum[i]%=MOD;
        }
        else{
            t[k].sum[1]=c*(t[k].r-t[k].l+1);
            t[k].sum[2]=c*c*(t[k].r-t[k].l+1);
            t[k].sum[3]=c*c*c*(t[k].r-t[k].l+1);
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
    // freopen("P3373_2.in","r",stdin);
    // freopen("P3373_2.out","w",stdout);
    int n,m;
    while(scanf("%d%d%d",&n,&m,&MOD)==3){
        rep(i,1,n)scanf("%lld",&a[i]);
        build(1,1,n);
        rep(i,1,m){
            int op,x,y;
            LL c;
            scanf("%d%d%d",&op,&x,&y);
            if(op!=3){
                scanf("%lld",&c);
                change(1,x,y,op==1?2:1,c);
            }
            else printf("%lld\n",query(1,x,y,1)%MOD);
        }
    }
    return 0;
}