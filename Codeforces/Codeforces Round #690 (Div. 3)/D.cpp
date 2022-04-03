#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=3005;

int a[maxn],sum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n)sum[i]=sum[i-1]+a[i];
        int ans=INF;
        rep(i,1,n){
            int res=i-1,pre=i;
            rep(j,i+1,n){
                if(sum[j]-sum[pre]==sum[i]){
                    res+=j-pre-1;
                    pre=j;
                }
                else if(sum[j]-sum[pre]>sum[i]){
                    res=-1;
                    break;
                }
            }
            if(res!=-1&&pre==n)ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}