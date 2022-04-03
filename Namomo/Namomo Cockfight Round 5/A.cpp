#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    LL n;
    scanf("%lld",&n);
    LL ans=0;
    while(n){ans=max(n%10,ans);n/=10;}
    printf("%lld\n",ans);
    return 0;
}