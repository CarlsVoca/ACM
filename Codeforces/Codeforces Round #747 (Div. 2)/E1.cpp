#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int MOD=1e9+7;

int main(){
    int k;
    scanf("%d",&k);
    LL ans=6,base=4*4;
    rep(i,2,k){
        ans=ans*base%MOD;
        base=base*base%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}