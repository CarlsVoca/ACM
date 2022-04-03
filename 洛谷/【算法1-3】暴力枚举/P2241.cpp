#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    LL n,m;
    scanf("%lld%lld",&n,&m);
    LL tot=((n*m)*(n*m-1)/2-(m*(m-1)/2*n+n*(n-1)/2*m))/2+m*(m-1)/2*n+n*(n-1)/2*m+n*m,a=0;
    rep(i,1,n)
        rep(j,1,m){
            a+=min(n-i+1,m-j+1);
        }
    printf("%lld %lld\n",a,tot-a);
    return 0;
}