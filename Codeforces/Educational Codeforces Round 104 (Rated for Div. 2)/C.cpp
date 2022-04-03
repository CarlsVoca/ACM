#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

int res[maxn][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(n%2){
            rep(i,1,n){
                rep(j,i+1,n){
                    res[i][j]=(j-i)%2?1:-1;
                }
            }
            rep(i,1,n){
                rep(j,i+1,n){
                    printf("%d ",res[i][j]);
                }
            }
            putchar('\n');
        }
        else{
            for(int i=1;i<=n;i+=2)res[i][i+1]=0;
            rep(i,1,n){
                rep(j,i+1,n){
                    if((i%2)&&j==i+1)continue;
                    res[i][j]=(j-i)%2?1:-1;
                }
            }
            rep(i,1,n){
                rep(j,i+1,n){
                    printf("%d ",res[i][j]);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}