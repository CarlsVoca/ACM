#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    LL n;
    cin>>n;
    if(n<=999)puts("0");
    else if(n<=999999){
        printf("%lld\n",n-999);
    }
    else if(n<=999999999){
        printf("%lld\n",(n-999999)*2+(999999-999));
    }
    else if(n<=999999999999LL){
        printf("%lld\n",(n-999999999LL)*3+(999999999LL-999999LL)*2+(999999-999));    
    }
    else if(n<=999999999999999LL){
        printf("%lld\n",(n-999999999999LL)*4+(999999999999LL-999999999LL)*3+(999999999LL-999999LL)*2+(999999-999));        
    }
    else{
        printf("%lld\n",(n-999999999999999LL)*5+(999999999999999LL-999999999999LL)*4+(999999999999LL-999999999LL)*3+(999999999LL-999999LL)*2+(999999-999));
    }
    return 0;
}