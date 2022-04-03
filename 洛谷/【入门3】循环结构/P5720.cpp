#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int a;
    scanf("%d",&a);
    int cnt=0;
    while(a!=1){
        cnt++;
        a/=2;
    }
    printf("%d\n",cnt+1);
    return 0;
}