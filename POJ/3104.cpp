#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

LL a[maxn],tmp[maxn];
LL k;
int n;

bool check(LL x){
    rep(i,1,n)tmp[i]=a[i];
    rep(i,1,n)tmp[i]=max(0LL,tmp[i]-x);
    LL cnt=0;
    rep(i,1,n){
        if(tmp[i]){
            if(k==1)return 0;
            else cnt+=ceil((double)tmp[i]/(k-1));
        }
    }
    // printf("debug:x=%lld cnt=%lld\n",x,cnt);
    return cnt<=x;
}

int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%lld",&a[i]);
    scanf("%lld",&k);
    LL l=0,r=INF;
    while(l<r){
        LL mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}