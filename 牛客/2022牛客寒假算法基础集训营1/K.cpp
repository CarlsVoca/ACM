#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int dp[maxn][4][4];
string s;

int main(){
    int n;
    scanf("%d",&n);
    cin>>s;
    s=' '+s;
    rep(i,1,n)rep(j,0,2)rep(k,0,2)dp[i][j][k]=-INF;
    dp[2][0][0]=2;
    dp[2][0][1]=1;
    dp[2][1][0]=1;
    dp[2][0][2]=1;
    dp[2][2][0]=1;
    dp[2][1][1]=0;
    dp[2][1][2]=0;
    dp[2][2][1]=0;
    dp[2][2][2]=0;
    rep(i,3,n){
        rep(j,0,2){    
            rep(k,0,2){
                rep(l,0,2){
                    int cnt[3]={0};
                    cnt[j]++;
                    cnt[k]++;
                    cnt[l]++;
                    if(s[i]=='G'){
                        if(cnt[0]>cnt[1])dp[i][j][k]=max(dp[i][j][k],dp[i-1][l][j]+(k==0));
                    }
                    if(s[i]=='R'){
                        if(cnt[0]<cnt[1])dp[i][j][k]=max(dp[i][j][k],dp[i-1][l][j]+(k==0));    
                    }
                    if(s[i]=='B'){
                        if(cnt[0]==cnt[1])dp[i][j][k]=max(dp[i][j][k],dp[i-1][l][j]+(k==0));
                    }
                }
            }
        }
    }
    int ans=-INF;
    rep(i,0,2)rep(j,0,2)ans=max(ans,dp[n][i][j]);
    printf("%d\n",(ans>-INF+100)?ans:-1);
    return 0;
}