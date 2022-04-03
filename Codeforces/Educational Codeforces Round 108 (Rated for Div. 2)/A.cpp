#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL a,b,d;
        scanf("%lld%lld%lld",&a,&b,&d);
        if(a<b)swap(a,b);
        if(a>b+b*d)puts("NO");
        else puts("YES");
    }
    return 0;
}