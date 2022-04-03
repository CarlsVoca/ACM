#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=22;

int a[maxn];

int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    rep(i,r+1,n)a[i]=1;
    do{
        rep(i,1,n)if(!a[i])printf("%3d",i);
        putchar('\n');
    }while(next_permutation(a+1,a+n+1));
    return 0;
}