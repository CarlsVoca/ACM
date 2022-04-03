#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

string s[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,0,n-1)cin>>s[i];
        int ans=0;
        rep(i,0,n-1)rep(j,0,m-1)if(s[i][j]=='1')ans++;
        printf("%d\n",3*ans);
        rep(i,1,n){
            rep(j,1,m){
                if(s[i-1][j-1]=='1'){
                    if(i==1&&j==1){
                        printf("%d %d %d %d %d %d\n",i,j,i,j+1,i+1,j+1);
                        printf("%d %d %d %d %d %d\n",i+1,j,i,j,i+1,j+1);
                        printf("%d %d %d %d %d %d\n",i+1,j,i,j+1,i,j);
                    }
                    else if(i==1){
                        printf("%d %d %d %d %d %d\n",i,j,i,j-1,i+1,j-1);
                        printf("%d %d %d %d %d %d\n",i+1,j,i,j,i+1,j-1);
                        printf("%d %d %d %d %d %d\n",i+1,j,i,j-1,i,j);
                    }
                    else if(j==1){
                        printf("%d %d %d %d %d %d\n",i,j,i,j+1,i-1,j+1);
                        printf("%d %d %d %d %d %d\n",i-1,j,i,j,i-1,j+1);
                        printf("%d %d %d %d %d %d\n",i-1,j,i,j+1,i,j);
                    }
                    else{
                        printf("%d %d %d %d %d %d\n",i,j,i,j-1,i-1,j-1);
                        printf("%d %d %d %d %d %d\n",i-1,j,i,j,i-1,j-1);
                        printf("%d %d %d %d %d %d\n",i-1,j,i,j-1,i,j);
                    }
                }
            }
        }
    }
    return 0;
}