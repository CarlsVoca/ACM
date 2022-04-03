#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

struct Edge{
    double y,l,r;
    int w;
    bool operator < (const Edge &e)const{
        return y<e.y;
    }
}e[maxn<<1];

double x[maxn<<1];

struct Node{
    int l,r,cnt;
    double sum1,sum2;
}t[maxn<<4];

void update(int k){
    if(t[k].cnt==0){
        t[k].sum1=t[k<<1].sum1+t[k<<1|1].sum1;
        t[k].sum2=t[k<<1].sum2+t[k<<1|1].sum2;
    }
    else if(t[k].cnt==1){
        t[k].sum1=x[t[k].r]-x[t[k].l];
        t[k].sum2=t[k<<1].sum1+t[k<<1|1].sum1;
    }
    else t[k].sum1=t[k].sum2=x[t[k].r]-x[t[k].l];
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].cnt=t[k].sum1=t[k].sum2=0;
    if(l==r-1){
        t[k<<1].l=t[k<<1|1].l=t[k<<1].r=t[k<<1|1].r=t[k<<1].sum1=t[k<<1].sum2=t[k<<1|1].sum1=t[k<<1|1].sum2=0;
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid,r);
}

void change(int k,int L,int R,int val){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].cnt+=val;
        update(k);
        return;
    }
    change(k<<1,L,R,val);
    change(k<<1|1,L,R,val);
    update(k);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            double l,r,t,d;
            scanf("%lf%lf%lf%lf",&l,&d,&r,&t);
            e[i]=Edge{d,l,r,1};
            e[i+n]=Edge{t,l,r,-1};
            x[i]=l,x[i+n]=r;
        }
        sort(e+1,e+2*n+1);
        sort(x+1,x+2*n+1);
        int m=unique(x+1,x+2*n+1)-x-1;
        rep(i,1,2*n)e[i].l=lower_bound(x+1,x+m+1,e[i].l)-x,e[i].r=lower_bound(x+1,x+m+1,e[i].r)-x;
        build(1,1,m);
        double ans=0;
        rep(i,1,2*n){
            ans+=(e[i].y-e[i-1].y)*t[1].sum2;
            change(1,e[i].l,e[i].r,e[i].w);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}