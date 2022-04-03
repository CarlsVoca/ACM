#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=10;

int a[maxn][maxn],tmp[maxn][maxn];

void change(int x,int y){
    tmp[x][y]^=1;
    tmp[x-1][y]^=1;
    tmp[x][y-1]^=1;
    tmp[x+1][y]^=1;
    tmp[x][y+1]^=1;
}

int main(){
    rep(i,1,4)rep(j,1,4)scanf("%1d",&a[i][j]);
    rep(i,0,(1<<4)-1){
        rep(ii,1,4)rep(jj,1,4)tmp[ii][jj]=a[ii][jj];
        rep(j,0,3){
            if((1<<j)&i){
                change(1,j+1);
            }
        }
        rep(ii,2,4){
            rep(jj,1,4){
                if(tmp[ii-1][jj]){
                    change(ii,jj);
                }
            }
        }
        bool flag=1;
        rep(ii,1,4)rep(jj,1,4)if(tmp[ii][jj])flag=0;
        if(flag){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}