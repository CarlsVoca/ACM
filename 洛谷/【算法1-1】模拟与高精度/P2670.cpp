#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

char s[maxn][maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%s",s[i]+1);
    rep(i,1,n){
        rep(j,1,m){
            if(s[i][j]=='*')putchar('*');
            else{
                int res=0;
                if(s[i-1][j-1]=='*')res++;
                if(s[i-1][j]=='*')res++;
                if(s[i][j-1]=='*')res++;
                if(s[i+1][j+1]=='*')res++;
                if(s[i+1][j]=='*')res++;
                if(s[i][j+1]=='*')res++;
                if(s[i-1][j+1]=='*')res++;
                if(s[i+1][j-1]=='*')res++;
                printf("%d",res);
            }
        }
        putchar('\n');
    }
    return 0;
}