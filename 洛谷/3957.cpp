#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=1000000000000000LL;
const int maxn=500005;

namespace Fast_IO{
    void read(int &x){
        x=0;int flag=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;if(ch==EOF)return;ch=getchar();}
        while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
        x*=flag;
    }
}
using namespace Fast_IO;

int x[maxn],s[maxn];
/*
namespace Segment_Tree{
    struct Node{
        int l,r;
        LL MAX;
    }t[maxn*4];
    inline void update(int k1){
        t[k1].MAX=max(t[k1<<1].MAX,t[k1<<1|1].MAX);
    }
    void build(int k1,int l,int r){
        t[k1].l=l;t[k1].r=r;
        if(l==r){
            t[k1].MAX=-INF;
            return;
        }
        int mid=(l+r)>>1;
        build(k1<<1,l,mid);
        build(k1<<1|1,mid+1,r);
        update(k1);
    }
    void change_point(int k1,int pos,LL k){
        if(pos>t[k1].r||pos<t[k1].l)return;
        if(t[k1].r==t[k1].l){
            t[k1].MAX=max(k,t[k1].MAX);
            return;
        }
        change_point(k1<<1,pos,k);
        change_point(k1<<1|1,pos,k);
        update(k1);
    }
    LL query(int k1,int L,int R){
        if(L>t[k1].r||R<t[k1].l)return -INF;
        if(L<=t[k1].l&&R>=t[k1].r){
            return t[k1].MAX;
        }
        return max(query(k1<<1,L,R),query(k1<<1|1,L,R));
    }
}
using namespace Segment_Tree;
*/

namespace ST{
    LL st[maxn][20];
    void add(int i,LL k){
        st[i][0]=k;
        for(int j=1;i-(1<<j)+1>=1;j++)st[i][j]=max(st[i][j-1],st[i-(1<<j-1)][j-1]);
    }
    LL query_max(int l,int r){
        int k=log2(r-l+1);
        return max(st[l+(1<<k)-1][k],st[r][k]);
    }
}
using namespace ST;

int n,d,k;

bool check(int mid){
    // LL res=0;
    // build(1,1,n);
    rep(i,1,n){
        LL tmp=-INF;
        if(x[i]-d+mid<0){
            add(i,tmp);
            continue;
        }
        int l=max(0,x[i]-d-mid),r=min(x[i]-d+mid,x[i]-1);
        if(l==0)tmp=s[i];
        int posl=lower_bound(x+1,x+n+1,l)-x,posr=upper_bound(x+1,x+n+1,r)-x-1;
        if(posl<=posr)tmp=max(tmp,query_max(posl,posr)+s[i]);
        add(i,tmp);
        if(tmp>=k)return 1;
    }
    return 0;
}

int main(){
    scanf("%d%d%d",&n,&d,&k);
    rep(i,1,n){read(x[i]);read(s[i]);}
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%d\n",check(l)?l:-1);
    return 0;
}