#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;

string s[maxn];
int dp[maxn][10];

int cul(char ch1,char ch2,char ch3,int x){
    int res=0;
    if(ch1-'0'==x/4)res++;
    x%=4;
    if(ch2-'0'==x/2)res++;
    x%=2;
    if(ch3-'0'==x/1)res++;
    return res;
}

bool check(int x,int y){
    if((x/4+y/4+x%4/2+y%4/2)%2==0)return 0;
    x%=4;
    if((x/2+y/2+x%2+y%2)%2==0)return 0;
    return 1;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,n-1)cin>>s[i];
    if(n>=4&&m>=4)puts("-1");
    else if(n==1||m==1)puts("0");
    else if(n==2||m==2){
        if(n==2){
            int cnt0=(int)(s[0][0]=='1')+(int)(s[1][0]=='1'),cnt1=(int)(s[0][1]=='1')+(int)(s[1][1]=='1');
            dp[1][0]=(cnt1%2==0?0:1)+abs(cnt0-1);
            dp[1][1]=abs(cnt1-1)+(cnt0%2==0?0:1);
            rep(i,2,m-1){
                cnt0=(int)(s[0][i-1]=='1')+(int)(s[1][i-1]=='1'),cnt1=(int)(s[0][i]=='1')+(int)(s[1][i]=='1');
                dp[i][0]=(cnt1%2==0?0:1)+dp[i-1][1];
                dp[i][1]=abs(cnt1-1)+dp[i-1][0];
            }
            printf("%d\n",min(dp[m-1][0],dp[m-1][1]));
        }
        else{
            int cnt0=(int)(s[0][0]=='1')+(int)(s[0][1]=='1'),cnt1=(int)(s[1][0]=='1')+(int)(s[1][1]=='1');
            dp[1][0]=(cnt1%2==0?0:1)+abs(cnt0-1);
            dp[1][1]=abs(cnt1-1)+(cnt0%2==0?0:1);
            rep(i,2,n-1){
                cnt0=(int)(s[i-1][0]=='1')+(int)(s[i-1][1]=='1'),cnt1=(int)(s[i][0]=='1')+(int)(s[i][1]=='1');
                dp[i][0]=(cnt1%2==0?0:1)+dp[i-1][1];
                dp[i][1]=abs(cnt1-1)+dp[i-1][0];
            }
            printf("%d\n",min(dp[n-1][0],dp[n-1][1]));
        }
    }
    else{
        if(n==3){
            rep(i,0,7)dp[0][i]=cul(s[0][0],s[1][0],s[2][0],i);
            rep(i,1,m-1){
                rep(j,0,7){
                    dp[i][j]=INF;
                    rep(k,0,7){
                        if(check(j,k)){
                            dp[i][j]=min(dp[i][j],dp[i-1][k]+cul(s[0][i],s[1][i],s[2][i],j));
                        }
                    }
                    // printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
                }
            }
            int ans=INF;
            rep(i,0,7)ans=min(ans,dp[m-1][i]);
            printf("%d\n",ans);
        }
        else{
            rep(i,0,7)dp[0][i]=cul(s[0][0],s[0][1],s[0][2],i);
            rep(i,1,n-1){
                rep(j,0,7){
                    dp[i][j]=INF;
                    rep(k,0,7){
                        if(check(j,k)){
                            dp[i][j]=min(dp[i][j],dp[i-1][k]+cul(s[i][0],s[i][1],s[i][2],j));
                        }
                    }
                }
            }
            int ans=INF;
            rep(i,0,7)ans=min(ans,dp[n-1][i]);
            printf("%d\n",ans);
        }
    }
    return 0;
}