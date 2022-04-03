#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a+b;
    if(c>=15&&b>=8)puts("1");
    else if(c>=10&&b>=3)puts("2");
    else if(c>=3)puts("3");
    else puts("4");
    return 0;
}