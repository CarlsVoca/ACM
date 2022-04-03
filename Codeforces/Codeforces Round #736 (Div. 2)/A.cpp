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
        int P;
        scanf("%d",&P);
        if(P&1){
            printf("%d %d\n",2,P-1);
        }
        else printf("%d %d\n",2,P);
    }
    return 0;
}