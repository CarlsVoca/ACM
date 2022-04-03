#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    rep(i,0,n-1){
        rep(j,1,n-i){
            printf("%02d",++cnt);
        }
        putchar('\n');
    }
    return 0;
}