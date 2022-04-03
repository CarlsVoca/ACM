#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

LL cntl[maxn],cntr[maxn];
int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",&a[i]);
            rep(j,a[i]-2,a[i]+2)cntl[j]=cntr[j]=0;
        }
        rep(i,1,n)cntr[a[i]]++;
        LL ans=0;
        rep(i,1,n){
            cntr[a[i]]--;
            ans+=cntl[a[i]-2]*(cntr[a[i]-2]+cntr[a[i]-1]+cntr[a[i]]);
            ans+=cntl[a[i]-1]*(cntr[a[i]-2]+cntr[a[i]-1]+cntr[a[i]]+cntr[a[i]+1]);
            ans+=cntl[a[i]]*(cntr[a[i]-2]+cntr[a[i]-1]+cntr[a[i]]+cntr[a[i]+1]+cntr[a[i]+2]);
            ans+=cntl[a[i]+1]*(cntr[a[i]-1]+cntr[a[i]]+cntr[a[i]+1]+cntr[a[i]+2]);
            ans+=cntl[a[i]+2]*(cntr[a[i]]+cntr[a[i]+1]+cntr[a[i]+2]);
            cntl[a[i]]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}