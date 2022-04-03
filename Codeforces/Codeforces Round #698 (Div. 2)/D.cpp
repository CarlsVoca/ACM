#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

LL a[maxn];

namespace Gcd{
    LL gcd(LL x,LL y){
        return y?gcd(y,x%y):x;
    }
}
using namespace Gcd;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        LL k;
        scanf("%d%lld",&n,&k);
        rep(i,1,n)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        LL G=a[2]-a[1];
        rep(i,3,n)G=gcd(G,a[i]-a[i-1]);
        bool flag=0;
        rep(i,1,n)if((k-a[1])%G==0){flag=1;break;}
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}