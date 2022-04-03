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
        int ans=9;
        for(LL i=0;i*114514<=999999999;i++){
            int res=0;
            for(LL j=1;j<=100000000;j*=10){
                if(i*114514/j%10!=n/j%10)res++;
            }
            ans=min(res,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}