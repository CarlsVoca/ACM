#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=55;

int a[maxn][maxn],k[maxn][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int sum=0;
        rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
        rep(i,1,3)rep(j,1,3)scanf("%d",&k[i][j]),sum+=k[i][j];
        if(k[1][1]!=sum){
            rep(i,1,n){
                rep(j,1,n-1){
                    printf("0 ");
                }
                printf("0\n");
            }
        }
        else{
            rep(i,1,n){
                rep(j,1,n-1){
                    printf("%d ",a[i][j]);
                }
                printf("%d\n",a[i][n]);
            }
        }
    }
    return 0;
}