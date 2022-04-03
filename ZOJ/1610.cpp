#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=8005;

struct Node{
    int l,r,c,lazy;
}t[maxn<<2];

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lazy=0;
    if(l==r){
        t[k].c=0;
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void pushdown(int k){
    if(!t[k].lazy)return;
    t[k<<1].c=t[k].lazy;
    t[k<<1].lazy=t[k].lazy;
    t[k<<1|1].c=t[k].lazy;
    t[k<<1|1].lazy=t[k].lazy;
    t[k].lazy=0;
}

void change(int k,int L,int R,int val){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].lazy=val;
        t[k].c=val;
        return;
    }
    pushdown(k);
    change(k<<1,L,R,val);
    change(k<<1|1,L,R,val);
}

int query(int k,int pos){
    if(t[k].l>pos||t[k].r<pos)return 0;
    if(t[k].l==t[k].r)return t[k].c;
    pushdown(k);
    return query(k<<1,pos)|query(k<<1|1,pos);
}

int ans[maxn];

int main(){
    int n;
    while(scanf("%d",&n)==1){
        int MAXr=0,MAXc=0;
        build(1,0,8001);
        rep(i,1,n){
            int l,r,c;
            scanf("%d%d%d",&l,&r,&c);
            change(1,l+1,r,c+1);
            MAXr=max(MAXr,r);
        }
        int pre=-1,cnt=0;
        rep(i,0,MAXr+1){
            int c=query(1,i);
            MAXc=max(MAXc,c);
            if(c==0){
                if(cnt){
                    ans[pre]++;
                    pre=c;
                    cnt=0;
                }
                else continue;
            }
            else if(c==pre)cnt++;
            else{
                ans[pre]++;
                pre=c;
                cnt=1;
            }
        }
        rep(i,1,MAXc){
            if(ans[i]){
                printf("%d %d\n",i-1,ans[i]);
                ans[i]=0;
            }
        }
        putchar('\n');
    }
    return 0;
}