#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

char s[maxn][maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,n)scanf("%s",s[i]+1);
        int ans=0;
        rep(i,1,n)if(s[i][m]!='D')ans++;
        rep(i,1,m)if(s[n][i]!='R')ans++;
        printf("%d\n",ans-2);
    }
    return 0;
}