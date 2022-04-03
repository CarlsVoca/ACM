#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

struct Node{
    int l,r,sum,lazy;
}t[maxn<<2];

void update(int k){
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lazy=0;
    if(l==r){
        t[k].sum=1;
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}

void pushdown(int k){
    if(!t[k].lazy)return;
    t[k<<1].lazy=t[k].lazy;
    t[k<<1].sum=(t[k<<1].r-t[k<<1].l+1)*t[k].lazy;
    t[k<<1|1].lazy=t[k].lazy;
    t[k<<1|1].sum=(t[k<<1|1].r-t[k<<1|1].l+1)*t[k].lazy;
    t[k].lazy=0;
}

void change(int k,int L,int R,int val){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].sum=val*(t[k].r-t[k].l+1);
        t[k].lazy=val;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,val);
    change(k<<1|1,L,R,val);
    update(k);
}

int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        build(1,1,n);
        int m;
        scanf("%d",&m);
        rep(i,1,m){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            change(1,x,y,z);
            // printf("debug:%d\n",t[1].sum);
        }
        printf("Case %d: The total value of the hook is %d.\n",++cas,t[1].sum);
    }
    return 0;
}