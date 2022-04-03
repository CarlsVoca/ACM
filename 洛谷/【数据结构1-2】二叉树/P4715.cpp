#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,1<<n)scanf("%d",&a[i]);
    int MAX1=0,MAX2=0,pos1,pos2;
    rep(i,1,1<<n-1)if(a[i]>MAX1)MAX1=a[i],pos1=i;
    rep(i,(1<<n-1)+1,1<<n)if(a[i]>MAX2)MAX2=max(MAX2,a[i]),pos2=i;
    printf("%d\n",MAX1<MAX2?pos1:pos2);
    return 0;
}