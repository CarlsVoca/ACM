#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

void solve(LL x){
    if(x==1)printf("%lld ",x);
    else{
        if(x&1)solve(x*3+1);
        else solve(x/2);
        printf("%lld ",x);
    }
}

int main(){
    LL n;
    scanf("%lld",&n);
    solve(n);
    return 0;
}