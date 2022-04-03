#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=25;

int a[maxn][maxn];

bool judge(int x,int y){
    return a[x-1][y]||a[x][y-1]||a[x+1][y]||a[x][y+1]||a[x-1][y-1]||a[x-1][y+1]||a[x+1][y+1]||a[x+1][y-1];
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        rep(i,1,n){
            if(i==1){
                a[1][1]=1;
                rep(j,2,m){
                    if(j&1)a[i][j]=1;
                }
            }
            if(i==n){
                rep(j,1,m){
                    if(!judge(i,j))a[i][j]=1;
                }
            }
            else{
                if(!judge(i,1))a[i][1]=1;
                if(!judge(i,m))a[i][m]=1;
            }
        }
        rep(i,1,n){
            rep(j,1,m){
                printf("%d",a[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}