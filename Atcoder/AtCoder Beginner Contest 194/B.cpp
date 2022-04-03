#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int a[maxn],b[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int ans=INF;
    rep(i,1,n)scanf("%d%d",&a[i],&b[i]),ans=min(ans,a[i]+b[i]);
    rep(i,1,n){
        rep(j,i+1,n){
            ans=min(ans,max(a[i],b[j]));
            ans=min(ans,max(b[i],a[j]));
        }
    }
    printf("%d\n",ans);
    return 0;
}