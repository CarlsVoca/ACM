#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int MOD=20010817;
const int maxn=5e6+5;

int dp[maxn];

int main(){
    string s;
    cin>>s;
    int n=s.length();s=' '+s;
    dp[1]=1;
    LL ans=1;
    int a,b;
    a=b=(int)s[1];
    int fac=63;
    rep(i,2,n){
        a=a*63+s[i];
        b=b+s[i]*fac;
        fac*=63;
        if(a==b)ans+=(dp[i]=dp[i/2]+1);
    }
    printf("%lld\n",ans);
    return 0;
}