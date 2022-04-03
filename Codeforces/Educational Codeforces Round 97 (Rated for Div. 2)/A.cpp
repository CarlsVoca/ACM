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
        int l,r;
        scanf("%d%d",&l,&r);
        int a=r+1;
        if(l%a>=a/2.0)puts("YES");
        else puts("NO");
    }
    return 0;
}