#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define Len(k,p) (t[p][k].r-t[p][k].l+1)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

struct Node{
    int l,r,lsum,rsum,sum,lazy;
}t[3][maxn<<2];

void update(int k,int p){
    t[p][k].lsum=(t[p][k<<1].lsum==Len(k<<1,p)?Len(k<<1,p)+t[p][k<<1|1].lsum:t[p][k<<1].lsum);
    t[p][k].rsum=(t[p][k<<1|1].rsum==Len(k<<1|1,p)?Len(k<<1|1,p)+t[p][k<<1].rsum:t[p][k<<1|1].rsum);
    t[p][k].sum=max(max(t[p][k<<1].sum,t[p][k<<1|1].sum),t[p][k<<1].rsum+t[p][k<<1|1].lsum);
}

void build(int k,int l,int r,int p){
    t[p][k].l=l;t[p][k].r=r;
    t[p][k].lsum=t[p][k].rsum=t[p][k].sum=Len(k,p);
    t[p][k].lazy=-1;
    if(l==r)return;
    int mid=l+r>>1;
    build(k<<1,l,mid,p);
    build(k<<1|1,mid+1,r,p);
}

void pushdown(int k,int p){
    if(t[p][k].lazy==-1)return;
    int c=t[p][k].lazy;
    t[p][k<<1].lazy=c;
    t[p][k<<1].lsum=t[p][k<<1].rsum=t[p][k<<1].sum=c*Len(k<<1,p);
    t[p][k<<1|1].lazy=c;
    t[p][k<<1|1].lsum=t[p][k<<1|1].rsum=t[p][k<<1|1].sum=c*Len(k<<1|1,p);
    t[p][k].lazy=-1;
}

void change(int k,int L,int R,int c,int p){
    if(t[p][k].l>R||t[p][k].r<L)return;
    if(t[p][k].l>=L&&t[p][k].r<=R){
        t[p][k].lazy=c;
        t[p][k].lsum=t[p][k].rsum=t[p][k].sum=c*Len(k,p);
        return;
    }
    pushdown(k,p);
    change(k<<1,L,R,c,p);
    change(k<<1|1,L,R,c,p);
    update(k,p);
}

int query(int k,int num,int p){
    pushdown(k,p);
    // printf("[%d,%d]\n",t[p][k].l,t[p][k].r);
    if(t[p][k<<1].sum>=num)return query(k<<1,num,p);
    else if(t[p][k<<1].rsum+t[p][k<<1|1].lsum>=num)return t[p][k<<1].r-t[p][k<<1].rsum+1;
    else if(t[p][k<<1|1].sum>=num)return query(k<<1|1,num,p);
    return 0;
}

int main(){
    int CASE;
    scanf("%d",&CASE);
    rep(cas,1,CASE){
        printf("Case %d:\n",cas);
        int n,t;
        scanf("%d%d",&t,&n);
        build(1,1,t,0);
        build(1,1,t,1);
        string s;
        rep(i,1,n){
            cin>>s;
            if(s=="NS"){
                int x;
                scanf("%d",&x);
                int pos=query(1,x,0);
                if(pos){
                    printf("%d,don't put my gezi\n",pos);
                    change(1,pos,pos+x-1,0,0);
                    change(1,pos,pos+x-1,0,1);
                }
                else{
                    pos=query(1,x,1);
                    if(!pos)printf("wait for me\n");
                    else{
                        printf("%d,don't put my gezi\n",pos);
                        change(1,pos,pos+x-1,0,0);
                        change(1,pos,pos+x-1,0,1);        
                    }
                }
            }
            else if(s=="DS"){
                int x;
                scanf("%d",&x);
                int pos=query(1,x,0);
                if(pos){
                    printf("%d,let's fly\n",pos);
                    change(1,pos,pos+x-1,0,0);
                }
                else printf("fly with yourself\n");
            }
            else{
                printf("I am the hope of chinese chengxuyuan!!\n");
                int l,r;
                scanf("%d%d",&l,&r);
                change(1,l,r,1,0);
                change(1,l,r,1,1);
            }
        }
    }
    return 0;
}