#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int x;
    scanf("%d",&x);
    if(x%400==0||((x%100!=0)&&(x%4==0)))puts("1");
    else puts("0");
    return 0;
}