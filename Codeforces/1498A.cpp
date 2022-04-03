#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}

bool check(LL x){
    LL sum=0,tmp=x;
    while(tmp){
        sum+=tmp%10;
        tmp/=10;
    }
    return gcd(sum,x)!=1;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%lld",&n);
        while(1){
            if(check(n)){
                printf("%lld\n",n);
                break;
            }
            n++;
        }
    }
    return 0;
}