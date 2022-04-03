#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=505;

int a[maxn][maxn],tmp[maxn][maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)
        rep(j,1,n){
            a[i][j]=(i-1)*n+j;
        }
    while(m--){
        int x,y,r,t;
        scanf("%d%d%d%d",&x,&y,&r,&t);
        rep(i,x-r,x+r)rep(j,y-r,y+r)tmp[i][j]=a[i][j];
        if(t==0){
            rep(i,x-r,x+r)
                rep(j,y-r,y+r){
                    a[i][j]=tmp[x+r-(j-(y-r))][y-r+i-(x-r)];
                }
        }
        else{
            rep(i,x-r,x+r)
                rep(j,y-r,y+r){
                    a[i][j]=tmp[x-r+j-(y-r)][y+r-(i-(x-r))];
                }
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            printf("%d ",a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}