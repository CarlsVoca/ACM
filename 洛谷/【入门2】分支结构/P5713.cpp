#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int x;
    scanf("%d",&x);
    if(5*x<3*x+11)puts("Local");
    else puts("Luogu");
    return 0;
}