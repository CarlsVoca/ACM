#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=505;

int a[maxn][maxn],b[maxn][maxn];

namespace Gcd{
    int gcd(int x,int y){
        return y?gcd(y,x%y):x;
    }
}
using namespace Gcd;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)rep(j,1,m)scanf("%d",&a[i][j]);
    int t=1;
    rep(i,1,16)t=t*i/gcd(t,i);
    // printf("%d\n",t);
    rep(i,1,n)rep(j,1,m){
        b[i][j]=t;
        if((i+j)%2)b[i][j]-=a[i][j]*a[i][j]*a[i][j]*a[i][j];
    }
    rep(i,1,n){
        rep(j,1,m-1){
            printf("%d ",b[i][j]);
        }
        printf("%d\n",b[i][m]);
    }
    return 0;
}