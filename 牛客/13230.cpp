#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=55;

bool dp[maxn][maxn][maxn][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string a,b;
        cin>>a>>b;
        int n=a.length(),m=b.length();
        a=' '+a;b=' '+b;
        int ans=0;
        for(int len=1;len<=n;len++){
            for(int i=1,j;i+len-1<=n;i++){
                j=len+i-1;
                if(len==1)dp[i][j][0][0]=1;
                else if(len==2)dp[i][j][0][0]=(a[i]==a[j]);
                else dp[i][j][0][0]=(dp[i+1][j-1][0][0]&&a[i]==a[j]);
                if(dp[i][j][0][0])ans=max(ans,j-i+1);
            }
        }
        for(int len=1;len<=m;len++){
            for(int i=1,j;i+len-1<=m;i++){
                j=len+i-1;
                if(len==1)dp[0][0][i][j]=1;
                else if(len==2)dp[0][0][i][j]=(b[i]==b[j]);
                else dp[0][0][i][j]=(dp[0][0][i+1][j-1]&&b[i]==b[j]);
                if(dp[0][0][i][j])ans=max(ans,j-i+1);
            }
        }
        for(int lena=1;lena<=n;lena++){
            for(int l1=1;l1+lena-1<=n;l1++){
                for(int lenb=1;lenb<=m;lenb++){
                    for(int l2=1;l2+lenb-1<=m;l2++){
                        int r1=l1+lena-1,r2=l2+lenb-1;
                        dp[l1][r1][l2][r2]=0;
                        if(lena>2)dp[l1][r1][l2][r2]|=(a[l1]==a[r1]&&dp[l1+1][r1-1][l2][r2]);
                        else if(lena==2)dp[l1][r1][l2][r2]|=(a[l1]==a[r1]&&dp[0][0][l2][r2]);
                        if(lenb>2)dp[l1][r1][l2][r2]|=(b[l2]==b[r2]&&dp[l1][r1][l2+1][r2-1]);
                        else if(lenb==2)dp[l1][r1][l2][r2]|=(b[l2]==b[r2]&&dp[l1][r1][0][0]);
                        if(lena==1&&lenb==1)dp[l1][r1][l2][r2]=(a[l1]==b[l2]);
                        else if(lena==1){
                            dp[l1][r1][l2][r2]|=(a[r1]==b[l2]&&dp[0][0][l2+1][r2]);
                            dp[l1][r1][l2][r2]|=(a[l1]==b[r2]&&dp[0][0][l2][r2-1]);
                        }
                        else if(lenb==1){
                            dp[l1][r1][l2][r2]|=(a[r1]==b[l2]&&dp[l1][r1-1][0][0]);
                            dp[l1][r1][l2][r2]|=(a[l1]==b[r2]&&dp[l1+1][r1][0][0]);
                        }
                        else{
                            dp[l1][r1][l2][r2]|=(a[r1]==b[l2]&&dp[l1][r1-1][l2+1][r2]);
                            dp[l1][r1][l2][r2]|=(a[l1]==b[r2]&&dp[l1+1][r1][l2][r2-1]);
                        }
                        if(dp[l1][r1][l2][r2])ans=max(ans,r1-l1+1+r2-l2+1);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}