#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const int maxn=105;

LL f[maxn];

LL solve(LL k){
    if(k==0)return 0;
    else if(k==1)return f[0];
    else if(k==2)return f[1];
    int p=(int)log2(k);
    return (f[p]+solve(k-(1<<p)))%MOD;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n,k;
        scanf("%lld%lld",&n,&k);
        f[0]=1;
        rep(i,1,100){
            f[i]=f[i-1]*n%MOD;
        }
        printf("%lld\n",solve(k));
    }
    return 0;
}