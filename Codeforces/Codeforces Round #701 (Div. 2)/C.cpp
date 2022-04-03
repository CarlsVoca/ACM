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
        LL x,y;
        scanf("%lld%lld",&x,&y);
        LL ans=0;
        rep(i,1,y-1){
            LL res=min(y,(x-i)/i)-i;
            if(res<=0)break;
            ans+=res;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

namespace Exgcd{
    void exgcd(int a,int b,int &x,int &y){
        if(!b)x=1,y=0;
        else{
            exgcd(b,a%b,y,x);
            y-=(a/b)*x;
        }
    }
}
using namespace Exgcd;