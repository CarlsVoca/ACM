#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int MAX=-INF,MIN=INF;
        rep(i,1,n){
            scanf("%d",&a[i]);
            MAX=max(MAX,a[i]);
            MIN=min(MIN,a[i]);
        }
        if(MAX==MIN)printf("%d\n",n);
        else puts("1");
    }
    return 0;
}