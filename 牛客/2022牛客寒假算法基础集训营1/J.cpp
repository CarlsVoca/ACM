#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10005;

int a[maxn],b[maxn];
int suma[maxn],sumb[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int A,B,n;
        scanf("%d%d%d",&A,&B,&n);
        rep(i,1,A){
            scanf("%d",&a[i]);
        }
        rep(i,1,B){
            scanf("%d",&b[i]);
        }
        if(A*2<n){
            puts("-1");
            continue;
        }
        sort(a+1,a+A+1,greater<int>());
        sort(b+1,b+B+1,greater<int>());
        rep(i,1,A)suma[i]=suma[i-1]+a[i];
        rep(i,1,B)sumb[i]=sumb[i-1]+b[i];
        int ans=0;
        rep(i,(n+1)/2,min(n,A)){
            if(n-i>B)continue;
            ans=max(ans,suma[i]+sumb[n-i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}