#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

struct Node{
    int l,r,sum,lazy;
}t[maxn<<2];

void update(int k){
    t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lazy=-1;t[k].sum=0;
    if(l==r)return;
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void pushdown(int k){
    if(t[k].lazy==-1)return;
    t[k<<1].sum=t[k].lazy*(t[k<<1].r-t[k<<1].l+1);
    t[k<<1].lazy=t[k].lazy;
    t[k<<1|1].sum=t[k].lazy*(t[k<<1|1].r-t[k<<1|1].l+1);
    t[k<<1|1].lazy=t[k].lazy;
    t[k].lazy=-1;
}

void change(int k,int L,int R,int c){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].sum=c*(t[k].r-t[k].l+1);
        t[k].lazy=c;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,c);
    change(k<<1|1,L,R,c);
    update(k);
}

int query(int k,int L,int R){
    if(t[k].l>R||t[k].r<L)return 0;
    if(t[k].l>=L&&t[k].r<=R)return t[k].sum;
    pushdown(k);
    return query(k<<1,L,R)+query(k<<1|1,L,R);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        build(1,0,n-1);
        rep(i,1,m){
            int k,a,b;
            scanf("%d%d%d",&k,&a,&b);
            if(k==1){
                if(n-1-a+1-query(1,a,n-1)==0){
                    puts("Can not put any one.");
                    continue;
                }
                int l=a,r=n-1;
                while(l<r){
                    int mid=l+r>>1;
                    if(mid-a+1-query(1,a,mid))r=mid;
                    else l=mid+1;
                }
                int ll=l;
                l=a,r=n-1;
                while(l<r){
                    int mid=l+r>>1;
                    if(mid-a+1-query(1,a,mid)>=b)r=mid;
                    else l=mid+1;
                }
                int rr=l;
                if(l-a+1-query(1,a,l)<b){
                    int tmp=l-a+1-query(1,a,l);
                    l=a,r=n-1;
                    while(l<r){
                        int mid=l+r>>1;
                        if(mid-a+1-query(1,a,mid)>=tmp)r=mid;
                        else l=mid+1;
                    }
                    rr=l;
                }
                change(1,ll,rr,1);
                printf("%d %d\n",ll,rr);
            }
            else{
                printf("%d\n",query(1,a,b));
                change(1,a,b,0);
            }
        }
        putchar('\n');
    }
    return 0;
}