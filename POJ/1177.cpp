#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<ctime>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

struct Segment{
    int h,l,r,tp;
    bool operator < (const Segment &l)const{
        return h<l.h;
    }
}l[maxn<<1];

int x[maxn<<1];

struct Node{
    int l,r,cnt,num;
    LL sum;
    bool ll,rr;
}t[maxn<<4];

void update(int k){
    if(t[k].cnt){
        t[k].sum=x[t[k].r]-x[t[k].l];
        t[k].num=1;
        t[k].ll=t[k].rr=1;
    }
    else{
        t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
        t[k].num=t[k<<1].num+t[k<<1|1].num-(t[k<<1].rr&&t[k<<1|1].ll);
        t[k].ll=t[k<<1].ll;
        t[k].rr=t[k<<1|1].rr;
    }
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].cnt=t[k].sum=t[k].ll=t[k].rr=t[k].num=0;
    if(r-l==1)return;
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid,r);
}

void change(int k,int L,int R,int x){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].cnt+=x;
        update(k);
        return;
    }
    change(k<<1,L,R,x);
    change(k<<1|1,L,R,x);
    update(k);
}

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        l[i]=(Segment){y1,x1,x2,1};
        l[i+n]=(Segment){y2,x1,x2,-1};
        x[i]=x1;x[i+n]=x2;
    }
    sort(l+1,l+2*n+1);
    sort(x+1,x+2*n+1);
    int m=unique(x+1,x+2*n+1)-x-1;
    rep(i,1,2*n)l[i].l=lower_bound(x+1,x+m+1,l[i].l)-x,l[i].r=lower_bound(x+1,x+m+1,l[i].r)-x;
    build(1,1,m);
    LL ans=0,pre=0;
    rep(i,1,2*n){
        ans+=t[1].num*2*(l[i].h-l[i-1].h);
        change(1,l[i].l,l[i].r,l[i].tp);
        ans+=(t[1].sum-pre)>0?(t[1].sum-pre):-(t[1].sum-pre);
        pre=t[1].sum;
    }
    printf("%lld\n",ans);
    return 0;
}