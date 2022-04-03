#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    LL ans=0;
    rep(i,1,n){
        scanf("%d",&a[i]);
        if(a[i]>a[i-1])ans+=a[i]-a[i-1];
    }
    printf("%lld\n",ans);
    return 0;
}