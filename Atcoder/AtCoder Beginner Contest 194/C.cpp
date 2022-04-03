#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=300005;

LL a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    LL sum=0;
    rep(i,1,n)scanf("%lld",&a[i]),sum+=a[i];
    LL ans=0;
    rep(i,1,n)ans+=a[i]*a[i]*(n-1);
    rep(i,1,n)ans-=a[i]*(sum-a[i]);
    printf("%lld\n",ans);
    return 0;
}