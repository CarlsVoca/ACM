#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        rep(j,1,n){
            printf("%02d",(i-1)*n+j);
        }
        putchar('\n');
    }
    putchar('\n');
    int cnt=0;
    rep(i,1,n){
        rep(j,1,n-i)printf("  ");
        rep(j,1,i)printf("%02d",++cnt);
        putchar('\n');
    }
    return 0;
}