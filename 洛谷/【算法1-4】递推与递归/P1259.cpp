#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n;
    scanf("%d",&n);
    per(i,n,4){
        rep(j,1,i)putchar('o');
        rep(j,1,i)putchar('*');
        printf("--");
        rep(j,1,n-i)printf("o*");
        putchar('\n');
        rep(j,1,i-1)putchar('o');
        printf("--");
        rep(j,1,i-1)putchar('*');
        rep(j,1,n-i+1)printf("o*");
        putchar('\n');
    }
    printf("ooo*o**--*");
    rep(i,1,n-4)printf("o*");
    putchar('\n');
    printf("o--*o**oo*");
    rep(i,1,n-4)printf("o*");
    putchar('\n');
    printf("o*o*o*--o*");
    rep(i,1,n-4)printf("o*");
    putchar('\n');
    printf("--o*o*o*o*");
    rep(i,1,n-4)printf("o*");
    putchar('\n');
    return 0;
}