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
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==b&&a==0)puts("0");
        else if(a==b)puts("1");
        else if(abs(a-b)&1)puts("-1");
        else puts("2");
    }
    return 0;
}