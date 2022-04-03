#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x7fffffff;
const int maxn=2e5+5;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        LL k;
        scanf("%d%lld",&n,&k);
        int MAX=-INF;
        rep(i,1,n){
            scanf("%d",&a[i]);
            MAX=max(MAX,a[i]);
        }
        rep(i,1,n)a[i]=MAX-a[i];
        if(k&1){
            rep(i,1,n)printf("%d ",a[i]);
            putchar('\n');
            continue;
        }
        MAX=-INF;
        rep(i,1,n)MAX=max(a[i],MAX);
        rep(i,1,n)a[i]=MAX-a[i];
        rep(i,1,n)printf("%d ",a[i]);
        putchar('\n');
    }
    return 0;
}