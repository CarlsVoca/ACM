#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int a[maxn][maxn],b[maxn][maxn],tmp[maxn][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)rep(j,1,n)scanf("%1d",&a[i][j]);
        rep(i,1,n)rep(j,1,n)scanf("%1d",&b[i][j]);
        bool flag=1;
        rep(i,1,n){
            rep(j,1,n){
                tmp[i][j]=a[i][j]^a[1][j]^b[1][j];
                // printf("%d",tmp[i][j]);
            }
            // putchar('\n');
        }
        rep(i,1,n){
            bool f1=1;
            rep(j,1,n)if(tmp[i][j]!=b[i][j])f1=0;
            bool f2=1;
            rep(j,1,n)if(tmp[i][j]==b[i][j])f2=0;
            if(f1||f2)continue;
            else{flag=0;break;}
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}