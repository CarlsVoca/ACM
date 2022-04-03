#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=100005;

LL a[maxn],sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        LL MAX=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
            MAX=max(MAX,a[i]);
        }
        LL k=ceil(sum[n]*1.0/(n-1));
        k=max(k,MAX);
        printf("%lld\n",k*(n-1)-sum[n]);
    }
    return 0;
}