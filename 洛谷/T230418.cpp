#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld\n",1ll*n*(n-1)/2*m);
    rep(i,1,n){
        if(i&1)printf("0 ");
        else printf("%d ",m);
    }
    return 0;
}