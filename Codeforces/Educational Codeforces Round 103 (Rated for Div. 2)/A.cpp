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
        if(k<n){
            if(n%k==0)puts("1");
            else puts("2");
        }
        else{
            printf("%d\n",k%n==0?k/n:k/n+1);
        }
    }
    return 0;
}