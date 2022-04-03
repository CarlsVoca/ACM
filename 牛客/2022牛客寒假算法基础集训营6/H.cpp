#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

bool dp[11][1050];

int main(){
    int T;
    scanf("%d",&T);
    rep(n,1,10){
        dp[n][0]=0;
        for(int i=1;i<=(1<<n)-1;i++){
            dp[n][i]=0;
            for(int j=0;j<n;j++){
                if((1<<j)&i){
                    if(j==0){
                        if(dp[n][i^(1<<j)]==0){
                            dp[n][i]=1;
                            break;
                        }
                    }
                    for(int k=0;k<j;k++){
                        if(dp[n][i^(1<<j)^(1<<k)]==0){
                            dp[n][i]=1;
                            break;
                        }
                    }
                }
            }
        }
    }
    while(T--){
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        int x=0;
        per(i,n-1,0){
            if(s[i]=='w'){
                x|=(1<<i);
            }
        }
        if(dp[n][x])puts("Yes");
        else puts("No");
    }
    return 0;
}