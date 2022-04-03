#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];
int n;
LL p;

bool check(int x){
    LL cnt=0;
    rep(i,1,n){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r>>1)+1;
            if(a[mid]-a[i]<=x)l=mid;
            else r=mid-1;
        }
        cnt+=l-i;
    }
    return cnt>=p;
}

int main(){
    while(scanf("%d",&n)==1){
        p=(n*1LL*(n-1)/2+1)/2;
        rep(i,1,n)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        int l=0,r=INF;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}