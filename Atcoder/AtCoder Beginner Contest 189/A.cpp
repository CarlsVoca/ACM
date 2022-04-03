#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    char a,b,c;
    cin>>a>>b>>c;
    if(a==b&&b==c)puts("Won");
    else puts("Lost");
    return 0;
}