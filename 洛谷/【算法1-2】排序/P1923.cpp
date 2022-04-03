#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=5000005;

int a[maxn];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    k++;
    rep(i,1,n)scanf("%d",&a[i]);
    nth_element(a+1,a+k,a+n+1);
    printf("%d\n",a[k]);
    return 0;
}