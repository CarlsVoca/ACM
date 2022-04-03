#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=3005;

int a[maxn];
LL sum[maxn][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n){
            rep(j,1,n)sum[i][j]=sum[i-1][j];
            sum[i][a[i]]++;
        }
        LL res=0;
        rep(i,1,n){
            rep(j,i+1,n){
                res+=sum[i-1][a[j]]*(sum[n][a[i]]-sum[j][a[i]]);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}