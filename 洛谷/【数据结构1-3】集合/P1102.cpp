#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int a[maxn];

int main(){
    int n,c;
    scanf("%d%d",&n,&c);
    rep(i,1,n)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    LL ans=0;
    rep(i,1,n){
        int l=lower_bound(a+1,a+n+1,a[i]-c)-a,r=upper_bound(a+1,a+n+1,a[i]-c)-a;
        if(a[i]-a[l]==c)ans+=r-l;
    }
    if(c==0)printf("%lld\n",(ans-n)/2);
    else printf("%lld\n",ans);
    return 0;
}