#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

struct Data{
    LL a,b;
    bool operator < (const Data& d)const{
        return a<d.a;
    } 
}d[maxn];

LL sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%lld",&d[i].a);
        rep(i,1,n)scanf("%lld",&d[i].b);
        sort(d+1,d+n+1);
        rep(i,1,n)sum[i]=sum[i-1]+d[i].b;
        LL ans=d[n].a;
        rep(i,0,n)ans=min(ans,max(sum[n]-sum[i],d[i].a));
        printf("%lld\n",ans);
    }
    return 0;
}