#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int ans=0;
        while(n){
            ans=max(ans,n%10);
            n/=10;
        }
        printf("%d\n",ans);
    }
    return 0;
}