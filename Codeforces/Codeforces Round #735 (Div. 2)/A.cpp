#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=1e5+5;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        LL ans=0;
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n-1){
            ans=max(ans,1LL*a[i]*a[i+1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}