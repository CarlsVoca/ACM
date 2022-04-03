#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        ans+=max(0,x-10);
    }
    printf("%d\n",ans);
    return 0;
}