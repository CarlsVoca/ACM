#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

const int maxn=105;

int a[maxn],sum=0;
bool dp[100005];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]),sum+=a[i];
    dp[0]=1;
    rep(i,1,n){
        per(j,sum-a[i],0){
            if(dp[j]){
                dp[j+a[i]]=1;
            }
        }
    }
    int ans=sum;
    rep(i,0,sum){
        if(dp[i])ans=min(ans,max(sum-i,i));
    }
    printf("%d\n",ans);
    return 0;
}