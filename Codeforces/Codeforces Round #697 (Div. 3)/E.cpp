#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;
const int p=1e9+7;

int a[maxn];
LL C[maxn][maxn];

bool cmp(int a,int b){return a>b;}

int main(){
    int T;
    scanf("%d",&T);
    C[0][0]=1;
    for(int i=1;i<=1000;++i){
        for(int j=0;j<=i;++j){
            if(j==0||j==i) C[i][j]=1%p;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
        }   
    }
    // printf("%lld\n",C[1][1]);
    while(T--){
        // puts("Carls");
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        int l=-1,r=-1;
        rep(i,1,n){
            if(a[i]==a[k]&&l==-1)l=i;
            if(a[i]==a[k]&&(i==n||a[i+1]!=a[k]))r=i;
        }
        printf("%lld\n",C[r-l+1][k-l+1]%p);
    }
    return 0;
}