#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=5005;

int a[5][maxn],cnt[5],f[maxn][maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,4)rep(j,1,n)scanf("%1d",&a[i][j]);
    memset(cnt,0,sizeof(cnt));
    rep(i,1,4)rep(j,1,n)if(a[i][j])cnt[i]++;
    int ct=0;
    rep(i,1,n){
        if(a[1][i]){
            if(a[2][i])ct+=cnt[2]-1;
            else ct+=cnt[2];
        }
    }
    rep(i,1,n){
        rep(j,i+1,n){
            int num1=0,num2=0;
            num1+=a[1][i];
            num1+=a[1][j];
            num2+=a[2][i];
            num2+=a[2][j];
            f[i][j]=ct;
            f[i][j]-=(cnt[1]-num1)*num2;
            f[i][j]-=(cnt[2]-num2)*num1;
            if(a[1][i]&&a[2][j])f[i][j]--;
            if(a[1][j]&&a[2][i])f[i][j]--;
            // if(a[1][i]&&a[1][j]&&a[2][i]&&a[2][j]){
            //     f[i][j]=ct-2-(cnt[2]-2)*2-(cnt[1]-2)*2;
            // }
            // if(a[1][i]&&a[1][j]&&a[2][i]&&!a[2][j]){
            //     f[i][j]=ct-1-(cnt[2]-1)*2-(cnt[1]-2);
            // }
            // if(a[1][i]&&a[1][j]&&!a[2][i]&&a[2][j]){
            //     f[i][j]=ct-1-(cnt[2]-1)*2-(cnt[1]-2);
            // }
            // if(!a[1][i]&&a[1][j]&&a[2][i]&&a[2][j]){
            //     f[i][j]=ct-1-(cnt[1]-1)*2-(cnt[2]-2);
            // }
            // if(a[1][i]&&!a[1][j]&&a[2][i]&&a[2][j]){
            //     f[i][j]=ct-1-(cnt[1]-1)*2-(cnt[2]-2);
            // }
            // if(a[1][i]&&a[1][j]&&!a[2][i]&&!a[2][j]){
            //     f[i][j]=ct-(cnt[2])*2;
            // }
            // if(!a[1][i]&&!a[1][j]&&a[2][i]&&a[2][j]){
            //     f[i][j]=ct-(cnt[1])*2;
            // }
            // if(!a[1][i]&&!a[1][j]&&!a[2][i]&&!a[2][j]){
            //     f[i][j]=ct;
            // }
        }
    }
    LL ans=0;
    rep(i,1,n)rep(j,1,n){
        if(i==j)continue;
        if(a[3][i]&&a[4][j]){
            ans+=f[min(i,j)][max(i,j)];
        }
    }
    printf("%lld\n",ans);
    return 0;
}