#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

int a[maxn];

namespace Fast_IO{
    int read(int &x){
        x=0;int flag=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;if(ch==EOF)return 0;ch=getchar();}
        while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
        return x*=flag;
    }
}
using namespace Fast_IO;
/*
namespace Segment_Tree{
    struct Node{
        int l,r,sum;
    }t[maxn];
    inline void update(int k){
        t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
    }
    void build(int k,int l,int r){
        t[k].l=l,t[k].r=r;
        if(l==r){
            t[k].sum=a[l];
            return;
        }
        int mid=l+r>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        update(k);
    }
    void change_point(int k,int pos,int val){
        if(t[k].r<pos||t[k].l>pos)return;
        if(t[k].l==t[k].r){
            t[k].sum+=val;
            return;
        }
        change_point(k<<1,pos,val);
        change_point(k<<1|1,pos,val);
        update(k);
    }
    int query_sum(int k,int L,int R){
        if(t[k].l>R||t[k].r<L)return 0;
        if(t[k].l>=L&&t[k].r<=R)return t[k].sum;
        return query_sum(k<<1,L,R)+query_sum(k<<1|1,L,R);
    }
}
using namespace Segment_Tree;
*/
int c[maxn];
int n;

void change(int x,int k){
    for(;x<=n;x+=x&-x)c[x]+=k;
}
int query(int x){
    int res=0;
    for(;x;x-=x&-x)res+=c[x];
    return res;
}

int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",++cas);
        scanf("%d",&n);
        rep(i,1,n)c[i]=0;
        rep(i,1,n)read(a[i]),change(i,a[i]);
        char s[6];
        while(scanf("%s",s)){
            if(strcmp(s,"End")==0)break;
            int i,j;
            read(i);read(j);
            if(strcmp(s,"Add")==0)change(i,j);
            else if(strcmp(s,"Sub")==0)change(i,-j);
            else printf("%d\n",query(j)-query(i-1));
        }
    }
    return 0;
}