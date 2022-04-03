#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn],r[maxn];

int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    rep(i,1,n)scanf("%d",&a[i]);
    LL ans=0;    
    rep(i,1,n-1){
        if(a[i]>x){
            ans+=a[i]-x;
            a[i]=x;
        }
        if(a[i]+a[i+1]>x){
            ans+=a[i]+a[i+1]-x;
            a[i+1]-=a[i]+a[i+1]-x;
        }
    }
    printf("%lld\n",ans);
    return 0;
}