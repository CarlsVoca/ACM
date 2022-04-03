#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

int gcd(int a,int b){
    return  b?gcd(b,a%b):a;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int x;
        scanf("%d",&x);
        int k=gcd(x,100);
        printf("%d\n",100/k);
    }
    return 0;
}