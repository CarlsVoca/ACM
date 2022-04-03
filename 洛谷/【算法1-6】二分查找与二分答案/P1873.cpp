#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1000005;

LL a[maxn],MAX,m;
int n;

namespace Binary_Search{
    bool check(LL ans){
        LL res=0;
        rep(i,1,n)res+=max(0LL,a[i]-ans);
        return res>=m;
    }
    LL do_main(){
        LL l=0,r=MAX;
        while(l<r){
            LL mid=(l+r)/2+1;
            if(check(mid))l=mid;
            else r=mid-1;
        }
        return l;
    }
}
using namespace Binary_Search;

int main(){
    scanf("%d%lld",&n,&m);
    rep(i,1,n)scanf("%lld",&a[i]),MAX=max(MAX,a[i]);
    printf("%lld\n",do_main());
    return 0;
}