#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    for(int i=n-1;i>=0;i--)putchar(s[i]);
    return 0;
}