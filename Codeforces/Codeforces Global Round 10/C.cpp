#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

LL a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%lld",&a[i]);
        LL ans=0;
        rep(i,2,n){
            if(a[i]<a[i-1])ans+=a[i-1]-a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}