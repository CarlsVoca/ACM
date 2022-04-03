#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n;
    scanf("%d",&n);
    int MIN=INF,MAX=-INF;
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        MIN=min(x,MIN);
        MAX=max(x,MAX);
    }
    printf("%d\n",MAX-MIN);
    return 0;
}