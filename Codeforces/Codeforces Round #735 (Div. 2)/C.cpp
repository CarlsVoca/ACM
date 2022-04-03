#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n,m;
        scanf("%lld%lld",&n,&m);
        LL tmp=0,ans=0;
        per(i,32,0){
            if(n&(1LL<<i)){
                tmp+=(1LL<<i);
            }
            else{
                if(tmp+(1LL<<i)-1>m);
                else{
                    tmp+=(1LL<<i);
                    ans+=(1LL<<i);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}