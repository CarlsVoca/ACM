#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=1005;

int a[maxn][maxn],sum[maxn][maxn];

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n)rep(j,1,m)scanf("%1d",&a[i][j]);
    rep(i,1,n)rep(j,1,m){
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    }
    int cnt=0;
    rep(i,k,n)rep(j,k,m)if(sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k])cnt++;
    printf("%d\n",cnt);
    return 0;
}