#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e4+5;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    int MAX=0;
    rep(i,1,n)scanf("%d",&a[i]),MAX=max(a[i],MAX);
    if(MAX==a[1])puts("S");
    else puts("N");
    return 0;
}