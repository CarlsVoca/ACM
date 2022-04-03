#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=100005;
const int INF=0x7fffffff;

LL c[maxn],Min[2][maxn],sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        Min[0][0]=Min[1][0]=INF;
        rep(i,1,n){
            scanf("%lld",&c[i]);
            sum[i]=sum[i-1]+c[i];
            Min[0][i]=Min[0][i-1];
            Min[1][i]=Min[1][i-1];
            Min[i&1][i]=min(Min[i&1][i],c[i]);
        }
        LL ans=(1LL<<59);
        rep(i,2,n){
            int cnt0=i/2,cnt1=(i+1)/2;
            ans=min(ans,(n-cnt0)*Min[0][i]+(n-cnt1)*Min[1][i]+sum[i]);
        }
        printf("%lld\n",ans);
    }
}