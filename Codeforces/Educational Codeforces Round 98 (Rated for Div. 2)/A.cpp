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
        int x,y;
        scanf("%d%d",&x,&y);
        int ans=min(x,y);
        x-=ans,y-=ans;
        ans*=2;
        if(x+y)ans+=(x+y)*2-1;
        printf("%d\n",ans);
    }
    return 0;
}