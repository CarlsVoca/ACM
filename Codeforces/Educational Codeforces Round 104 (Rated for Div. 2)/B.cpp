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
        int n,k;
        scanf("%d%d",&n,&k);
        int t;
        if(n%2)t=(k-1)/(n/2)+k-1;
        else t=k-1;
        printf("%d\n",t%n+1);
    }
    return 0;
}