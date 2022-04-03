#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    LL n;
    scanf("%lld",&n);
    LL cnt=0;
    while(n){
        if(n&1)cnt++;
        n>>=1;
    }
    printf("%lld\n",1LL<<cnt);
    return 0;
}