#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%lld",&n);
        printf("%lld %lld\n",-n+1,n);
    }
    return 0;
}