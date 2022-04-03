#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=55;

char s[maxn][maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%s",s[i]+1);
    int ans=INF;
    rep(i,1,n-2)
        rep(j,i+1,n-1){
            int res=0;
            rep(k,1,i)rep(l,1,m)if(s[k][l]!='W')res++;
            rep(k,i+1,j)rep(l,1,m)if(s[k][l]!='B')res++;
            rep(k,j+1,n)rep(l,1,m)if(s[k][l]!='R')res++;
            ans=min(ans,res);
        }
    printf("%d\n",ans);
    return 0;
}