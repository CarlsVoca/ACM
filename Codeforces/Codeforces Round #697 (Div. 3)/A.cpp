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
        LL n;
        cin>>n;
        LL k=log2(n);
        if(n==(1LL<<k))puts("NO");
        else puts("YES");
    }
    return 0;
}