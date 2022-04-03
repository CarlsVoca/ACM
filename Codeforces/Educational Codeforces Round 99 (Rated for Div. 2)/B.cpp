#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10005;

LL sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    rep(i,1,10000)sum[i]=sum[i-1]+i;
    while(T--){
        int x;
        scanf("%d",&x);
        int m=lower_bound(sum+1,sum+10000+1,x)-sum;
        if(sum[m]==x)printf("%d\n",m);
        else if(sum[m]-x==1)printf("%d\n",m+1);
        else printf("%d\n",m);
    }
    return 0;
}