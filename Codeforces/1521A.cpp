#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL A,B;
        scanf("%lld%lld",&A,&B);
        if(B==1)puts("NO");
        else printf("YES\n%lld %lld %lld\n",A,A*B,A*B+A);
    }
    return 0;
}