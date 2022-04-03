#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=305;

int h[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&h[i]);
    sort(h+1,h+1+n);
    LL nowh=0,ans=0;
    rep(i,1,n/2){
        ans+=(nowh-h[n-i+1])*(nowh-h[n-i+1]);
        nowh=h[n-i+1];
        ans+=(nowh-h[i])*(nowh-h[i]);
        nowh=h[i];
    }
    if(n&1)ans+=(nowh-h[n/2+1])*(nowh-h[n/2+1]);
    printf("%lld\n",ans); 
    return 0;
}