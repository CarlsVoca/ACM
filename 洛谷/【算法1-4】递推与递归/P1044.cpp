#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=20;

LL C[maxn*2][maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,2*n)C[i][0]=1;
    rep(i,1,2*n)
        rep(j,1,n){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    printf("%lld\n",C[2*n][n]-C[2*n][n-1]);
    return 0;
}