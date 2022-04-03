#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=305;

int a[maxn],ans[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&ans[i]);
    int l=1,r=n;
    for(int i=1;i<=n;i+=2){
        a[i]=ans[l++];
    }
    for(int i=2;i<=n;i+=2){
        a[i]=ans[r--];
    }
    rep(i,1,n-1)printf("%d ",a[i]);
    printf("%d\n",a[n]);
    }
    return 0;
}