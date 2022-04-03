#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];
LL sum[maxn];

int main(){
    int n,q,k;
    scanf("%d%d%d",&n,&q,&k);
    rep(i,1,n)scanf("%d",&a[i]);
    // if(n==1){
    //     rep(i,1,q){
    //         int l,r;
    //         scanf("%d%d",&l,&r);
    //         printf("%d\n",k-1);
    //     }
    //     return 0;
    // }
    a[0]=0,a[n+1]=k+1;
    rep(i,1,n)sum[i]=sum[i-1]+(a[i+1]-a[i-1]-2);
    rep(i,1,q){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==r)printf("%d\n",k-1);
        else printf("%lld\n",sum[r-1]-sum[l]+a[l+1]-2+k+1-a[r-1]-2);
    }
    return 0;
}