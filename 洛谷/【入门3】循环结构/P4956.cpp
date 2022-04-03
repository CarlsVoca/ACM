#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n;
    scanf("%d",&n);
    int x,k;
    rep(i,1,100){
        if(n/52/7>i&&(n/52/7-i)%3==0)x=i,k=(n/52/7-i)/3;
    }
    printf("%d\n%d\n",x,k);
    return 0;
}