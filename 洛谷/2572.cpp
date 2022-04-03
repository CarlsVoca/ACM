#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define Len(k) (t[k].r-t[k].l+1)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];

struct Node{
    int l,r,sum,ll[2],rr[2],maxlen[2],opp,lazy;
}t[maxn<<2];

void update(int k){
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
    if(t[k<<1].ll[1]==Len(k<<1))t[k].ll[1]=t[k<<1].ll[1]+t[k<<1|1].ll[1];
    else t[k].ll[1]=t[k<<1].ll[1];
    if(t[k<<1|1].rr[1]==Len(k<<1|1))t[k].rr[1]=t[k<<1|1].rr[1]+t[k<<1].rr[1];
    else t[k].rr[1]=t[k<<1|1].rr[1];
    if(t[k<<1].ll[0]==Len(k<<1))t[k].ll[0]=t[k<<1].ll[0]+t[k<<1|1].ll[0];
    else t[k].ll[0]=t[k<<1].ll[0];
    if(t[k<<1|1].rr[0]==Len(k<<1|1))t[k].rr[0]=t[k<<1|1].rr[0]+t[k<<1].rr[0];
    else t[k].rr[0]=t[k<<1|1].rr[0];
    t[k].maxlen[1]=max(max(t[k<<1].maxlen[1],t[k<<1|1].maxlen[1]),t[k<<1].rr[1]+t[k<<1|1].ll[1]);
    t[k].maxlen[0]=max(max(t[k<<1].maxlen[0],t[k<<1|1].maxlen[0]),t[k<<1].rr[0]+t[k<<1|1].ll[0]);
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lazy=-1;t[k].opp=0;
    if(l==r){
        t[k].sum=t[k].ll[1]=t[k].rr[1]=t[k].maxlen[1]=a[l];
        t[k].ll[0]=t[k].rr[0]=t[k].maxlen[0]=!a[l];
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}

void add1(int k,int x){
    t[k].sum=t[k].ll[1]=t[k].rr[1]=t[k].maxlen[1]=x*Len(k);
    t[k].ll[0]=t[k].rr[0]=t[k].maxlen[0]=(!x)*Len(k);
    t[k].lazy=x;
    t[k].opp=0;
}

void add2(int k){
    t[k].sum=Len(k)-t[k].sum;
    int tmp1=t[k].ll[0],tmp2=t[k].rr[0];
    t[k].ll[0]=t[k].ll[1];t[k].rr[0]=t[k].rr[1];
    t[k].ll[1]=tmp1;t[k].rr[1]=tmp2;
    t[k].opp^=1;
    int tmp=t[k].maxlen[0];
    t[k].maxlen[0]=t[k].maxlen[1];
    t[k].maxlen[1]=tmp;
}

void pushdown(int k){
    if(t[k].lazy!=-1)add1(k<<1,t[k].lazy),add1(k<<1|1,t[k].lazy);
    if(t[k].opp)add2(k<<1),add2(k<<1|1);
    t[k].lazy=-1;t[k].opp=0;
}

void change(int k,int L,int R,int x){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].sum=t[k].ll[1]=t[k].rr[1]=t[k].maxlen[1]=x*Len(k);
        t[k].ll[0]=t[k].rr[0]=t[k].maxlen[0]=(!x)*Len(k);
        t[k].lazy=x;
        t[k].opp=0;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,x);
    change(k<<1|1,L,R,x);
    update(k);
}

void opposite(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].sum=Len(k)-t[k].sum;
        int tmp1=t[k].ll[0],tmp2=t[k].rr[0];
        t[k].ll[0]=t[k].ll[1];t[k].rr[0]=t[k].rr[1];
        t[k].ll[1]=tmp1;t[k].rr[1]=tmp2;
        t[k].opp^=1;
        int tmp=t[k].maxlen[0];
        t[k].maxlen[0]=t[k].maxlen[1];
        t[k].maxlen[1]=tmp;
        return;
    }
    pushdown(k);
    opposite(k<<1,L,R);
    opposite(k<<1|1,L,R);
    update(k);
}

int query1(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return 0;
    if(t[k].l>=L&&t[k].r<=R)return t[k].sum;
    pushdown(k);
    return query1(k<<1,L,R)+query1(k<<1|1,L,R);
}

int query2(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return 0;
    if(t[k].l>=L&&t[k].r<=R)return t[k].maxlen[1];
    pushdown(k);
    return max(max(query2(k<<1,L,R),query2(k<<1|1,L,R)),min((t[k<<1].r-L+1),t[k<<1].rr[1])+min(R-t[k<<1|1].l+1,t[k<<1|1].ll[1]));
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,n-1)scanf("%d",&a[i]);
    build(1,0,n-1);
    rep(i,1,m){
        int tp,l,r;
        scanf("%d%d%d",&tp,&l,&r);
        if(tp==0||tp==1)change(1,l,r,tp);
        else if(tp==2)opposite(1,l,r);
        else if(tp==3)printf("%d\n",query1(1,l,r));
        else printf("%d\n",query2(1,l,r));
    }
    return 0;
}