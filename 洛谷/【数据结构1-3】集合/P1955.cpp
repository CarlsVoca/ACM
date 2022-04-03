#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

struct Data{
    int i,j,k;
    bool operator < (const Data &b)const{
        return k>b.k;
    }
}d[maxn];

int n,m;

namespace Union_Find{
    int f[maxn],Rank[maxn];
    void Pre(){
        memset(Rank,0,sizeof(Rank));
        for(int i=1;i<=m;i++)f[i]=i;
    }
    int Find(int x){
        return f[x]==x?x:f[x]=Find(f[x]);
    }
    void Union(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(fx!=fy){
            if(Rank[fx]>Rank[fy])f[fy]=fx;
            else{
                f[fx]=fy;
                if(Rank[fx]==Rank[fy])Rank[fy]++;
            }
        }
    }
}
using namespace Union_Find;

namespace Discretization{
    int tmp[maxn*2];
    void do_main(){
        rep(i,1,n)tmp[i*2-1]=d[i].i,tmp[i*2]=d[i].j;
        sort(tmp+1,tmp+2*n+1);
        m=unique(tmp+1,tmp+2*n+1)-tmp-1;
        for(int i=1;i<=n;i++)d[i].i=lower_bound(tmp+1,tmp+m+1,d[i].i)-tmp,d[i].j=lower_bound(tmp+1,tmp+m+1,d[i].j)-tmp;
    }
}
using namespace Discretization;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n)scanf("%d%d%d",&d[i].i,&d[i].j,&d[i].k);
        do_main();
        Pre();
        sort(d+1,d+n+1);
        bool flag=1;
        rep(i,1,n){
            if(d[i].k==1)Union(d[i].i,d[i].j);
            else{
                if(Find(d[i].i)==Find(d[i].j)){flag=0;break;}
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}