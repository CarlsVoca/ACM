#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10;

int a[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)a[i]=i;
    do{
        rep(i,1,n)printf("%5d",a[i]);
        putchar('\n');
    }while(next_permutation(a+1,a+n+1));
    return 0;
}