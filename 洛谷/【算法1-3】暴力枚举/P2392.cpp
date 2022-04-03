#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

bool f[25][125];

int main(){
    int n[5],ans=0;
    rep(i,1,4)scanf("%d",&n[i]);
    rep(T,1,4){
        int a[65],sum=0;
        rep(i,1,n[T])scanf("%d",&a[i]),sum+=a[i];
        memset(f,0,sizeof(f));
        f[0][0]=1;
        rep(i,1,n[T])
            rep(j,0,sum/2){
                if(f[i-1][j]||(j-a[i]>=0&&f[i-1][j-a[i]]))f[i][j]=1;
            }
        int res;
        rep(i,0,sum/2)if(f[n[T]][i])res=i;
        ans+=sum-res;
    }
    printf("%d\n",ans);
    return 0;
}