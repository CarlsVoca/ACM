#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=200005;
const LL INF=(1LL<<60);

int a[maxn];
LL sum[maxn],MAX[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL ans=-INF;
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sum[0]=0;
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
        MAX[k]=sum[k];
        for(int i=k+1;i<=n;i++)MAX[i]=max(MAX[i-1],sum[i]-sum[i-k]);
        for(int i=2*k;i<=n;i++)ans=max(ans,sum[i]-sum[i-k]+MAX[i-k]);
        printf("%lld\n",ans);
    }
    return 0;
}