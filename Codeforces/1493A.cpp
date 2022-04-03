#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        int m=n-k+k/2;
        printf("%d\n",m);
        rep(i,(k+1)/2,k-1)printf("%d ",i);
        rep(i,k+1,n)printf("%d ",i);
        putchar('\n');
    }
    return 0;
}