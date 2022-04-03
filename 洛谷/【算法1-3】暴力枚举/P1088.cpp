#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10005;

int a[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,m)next_permutation(a+1,a+n+1);
    rep(i,1,n)printf("%d ",a[i]);
    return 0;
}