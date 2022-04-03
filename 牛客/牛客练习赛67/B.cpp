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
        int n;
        scanf("%d",&n);
        int ans=0;
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            ans=max(ans,x);
        }
        printf("%d\n",ans);
    }
    return 0;
}