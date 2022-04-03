#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,x,y;
        scanf("%d%d%d%d",&n,&m,&x,&y);
        int ans=0;
        ans=max(ans,n-x+m-y);
        ans=max(ans,x-1+m-y);
        ans=max(ans,n-x+y-1);
        ans=max(ans,x-1+y-1);
        printf("%d\n",ans);
    }
    return 0;
}