#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn],b[maxn];

int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    rep(i,1,m)scanf("%d",&a[i]);
    rep(i,1,n)scanf("%d",&b[i]);
    sort(a+1,a+m+1);
    LL ans=0;
    rep(i,1,n){
        int pos=upper_bound(a+1,a+m+1,b[i])-a;
        if(pos==m+1)ans+=abs(a[pos-1]-b[i]);
        else if(pos==1)ans+=abs(a[pos]-b[i]);
        else ans+=min(abs(a[pos]-b[i]),abs(a[pos-1]-b[i]));
    }
    printf("%lld\n",ans);
    return 0;
}