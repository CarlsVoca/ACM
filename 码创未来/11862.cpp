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
        LL n,k;
        scanf("%lld%lld",&n,&k);
        if(k==0){printf("%lld\n",n);continue;}
        LL l=1,r=n-1;
        while(l<r){
            LL mid=l+r>>1;
            if((n-1+n-mid)*mid/2>=k)r=mid;
            else l=mid+1;
        }
        printf("%lld\n",n-l);
    }
    return 0;
}