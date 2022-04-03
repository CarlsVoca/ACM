#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

LL a[maxn],rest[maxn],neg[2][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%lld",&a[i]);
        rest[0]=0;
        rep(i,1,n)rest[i]=a[i]-rest[i-1];
        // rep(i,1,n)printf("debugrest[%d]:%d\n",i,rest[i]);
        int tar=n+1;
        rep(i,1,n){
            if(rest[i]<0){
                tar=i;
                break;
            }
        }
        if(tar==n+1&&rest[n]==0){
            puts("YES");
            continue;
        }
        // printf("debug:%d\n",tar);
        neg[n&1][n]=neg[n&1][n-1]=rest[n];
        neg[(n-1)&1][n-1]=rest[n-1];
        per(i,n-2,1){
            neg[1][i]=neg[1][i+1];
            neg[0][i]=neg[0][i+1];
            if(i&1)neg[1][i]=min(neg[1][i],rest[i]);
            else neg[0][i]=min(neg[0][i],rest[i]);
        }
        // rep(i,1,2)printf("debug:neg[%d]=%d %d\n",i,neg[0][i],neg[1][i]);
        bool flag=0;
        rep(i,1,min(tar,n-1)){
            if(rest[i]-a[i]+a[i+1]>=0&&neg[i&1][i+1]-2*a[i]+2*a[i+1]>=0&&neg[(i&1)^1][i]-2*a[i+1]+2*a[i]>=0){
                if((n&1)==(i&1)){
                    if(rest[n]-2*a[i]+2*a[i+1]==0){
                        flag=1;
                        break;
                    }
                }
                else{
                    if(rest[n]-2*a[i+1]+2*a[i]==0){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}