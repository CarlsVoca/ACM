#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int a[maxn][maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int h,w;
    scanf("%d%d",&h,&w);
    int cnt=0;
    for(int i=1;i+h-1<=n;i++){
        for(int j=1;j+w-1<=m;j++){
            if(a[i][j]==a[i][j+w-1]&&a[i][j]==a[i+h-1][j]&&a[i][j]==a[i+h-1][j+w-1])cnt++;
        }
    }
    if(cnt)puts("YES");
    else puts("NO");
    return 0;
}