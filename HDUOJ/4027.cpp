#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

LL a[maxn];

struct Node{
    int l,r;
    LL sum;
}t[maxn<<2];

void update(int k){
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    if(l==r){
        t[k].sum=a[l];
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}

void change(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R&&t[k].r-t[k].l+1==t[k].sum)return;
    if(t[k].l==t[k].r){t[k].sum=(int)sqrt(t[k].sum);return;}
    change(k<<1,L,R);
    change(k<<1|1,L,R);
    update(k);
}

LL query(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return 0;
    if(t[k].l>=L&&t[k].r<=R)return t[k].sum;
    return query(k<<1,L,R)+query(k<<1|1,L,R);
}

int main(){
    int n,cas=0;
    while(scanf("%d",&n)==1){
        printf("Case #%d:\n",++cas);
        rep(i,1,n)scanf("%lld",&a[i]);
        build(1,1,n);
        int m;
        scanf("%d",&m);
        rep(i,1,m){
            int t,l,r;
            scanf("%d%d%d",&t,&l,&r);
            if(l>r)swap(l,r);
            if(t==0)change(1,l,r);
            else printf("%lld\n",query(1,l,r));
        }
        putchar('\n');
    }
    return 0;
}