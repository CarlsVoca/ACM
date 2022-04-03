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
#define Len(k) (t[k].r-t[k].l+1)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

struct Node{
    int l,r,sum,lsum,rsum,lazy;
}t[maxn<<2];

void update(int k){
    t[k].lsum=(t[k<<1].lsum==Len(k<<1)?Len(k<<1)+t[k<<1|1].lsum:t[k<<1].lsum);
    t[k].rsum=(t[k<<1|1].rsum==Len(k<<1|1)?Len(k<<1|1)+t[k<<1].rsum:t[k<<1|1].rsum);
    t[k].sum=max(max(t[k<<1].sum,t[k<<1|1].sum),t[k<<1].rsum+t[k<<1|1].lsum);
}

void build(int k,int l,int r){
    t[k].l=l;t[k].r=r;
    t[k].lsum=t[k].rsum=t[k].sum=Len(k);
    t[k].lazy=-1;
    if(l==r)return;
    int mid=l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void pushdown(int k){
    if(t[k].lazy==-1)return;
    int c=t[k].lazy;
    t[k<<1].lazy=c;
    t[k<<1].lsum=t[k<<1].rsum=t[k<<1].sum=c*Len(k<<1);
    t[k<<1|1].lazy=c;
    t[k<<1|1].lsum=t[k<<1|1].rsum=t[k<<1|1].sum=c*Len(k<<1|1);
    t[k].lazy=-1;
}

void change(int k,int L,int R,int c){
    if(t[k].l>R||t[k].r<L)return;
    if(t[k].l>=L&&t[k].r<=R){
        t[k].lazy=c;
        t[k].lsum=t[k].rsum=t[k].sum=c*Len(k);
        return;
    }
    pushdown(k);
    change(k<<1,L,R,c);
    change(k<<1|1,L,R,c);
    update(k);
}

int query(int k,int num){
    pushdown(k);
    // printf("[%d,%d]\n",t[k].l,t[k].r);
    if(t[k<<1].sum>=num)return query(k<<1,num);
    else if(t[k<<1].rsum+t[k<<1|1].lsum>=num)return t[k<<1].r-t[k<<1].rsum+1;
    else if(t[k<<1|1].sum>=num)return query(k<<1|1,num);
    return 0;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    rep(i,1,m){
        int op;
        scanf("%d",&op);
        if(op==1){
            int k;
            scanf("%d",&k);
            int pos=query(1,k);
            printf("%d\n",pos);
            if(!pos)continue;
            else change(1,pos,pos+k-1,0);
        }
        else{
            int l,r;
            scanf("%d%d",&l,&r);
            change(1,l,l+r-1,1);
        }
    }
    return 0;
}