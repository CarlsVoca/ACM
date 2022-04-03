#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

string s;
int st[maxn][22][4];

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    cin>>s;
    s=' '+s;
    rep(i,1,n){
        if(s[i]=='D')st[i][0][0]=st[i][0][1]=st[i][0][2]=0;
        if(s[i]=='W')st[i][0][0]=st[i][0][1]=st[i][0][2]=1;
        if(s[i]=='L'){
            st[i][0][0]=0;
            st[i][0][1]=st[i][0][2]=-1;
        }
    }
    for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		    for(int k=0;k<=2;k++){
                st[i][j][k]=st[i][j-1][k]+st[i+(1<<j-1)][j-1][(k+st[i][j-1][k])%3];
            }
    while(q--){
        int l,r,s;
        scanf("%d%d%d",&l,&r,&s);
        int len=r-l+1;
        for(int j=22;j>=0;j--){
            if((1<<j)&len){
                s+=st[l][j][s%3];
                l+=(1<<j);
            }
        }
        printf("%d\n",s);
    }
    return 0;
}