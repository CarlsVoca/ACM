#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn];
int n;
LL k;

bool check(LL x){
    LL ned=0;
    rep(i,1,n){
        if(a[i]<x)ned+=x-a[i];
    }
    return k>=ned;
}

int main(){
    scanf("%d%lld",&n,&k);
    LL sum=0;
    rep(i,1,n){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    LL l=1,r=2e13;
    while(l<r){
        LL mid=((l+r)>>1)+1;
        if(!check(mid))r=mid-1;
        else l=mid;
    }
    printf("%lld\n",l);
    return 0;
}