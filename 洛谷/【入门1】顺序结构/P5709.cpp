#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int m,t,s;
    scanf("%d%d%d",&m,&t,&s);
    printf("%d\n",max(0,m-(int)ceil(s*1.0/t)));
    return 0;
}