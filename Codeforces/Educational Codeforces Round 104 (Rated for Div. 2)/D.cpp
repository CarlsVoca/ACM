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
        int n;
        scanf("%d",&n);
        LL l=1,r=1000000000;
        while(l<r){
            LL mid=((l+r)>>1)+1;
            LL a=mid*2-1;
            if(a*a/2+1<=n)l=mid;
            else r=mid-1;
        }
        if((l*2-1)*(l*2-1)/2+1>n)puts("0");
        else printf("%lld\n",l-1);
    }
    return 0;
}