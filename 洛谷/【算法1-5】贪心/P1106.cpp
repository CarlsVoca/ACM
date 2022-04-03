#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    string s;
    int k;
    cin>>s>>k;
    int n=s.length();
    if(k>=n-1){
        int MIN=INF;
        rep(i,0,n-1)MIN=min(MIN,s[i]-'0');
        printf("%d\n",MIN);
        return 0;
    }
    bool flag=0;
    rep(i,1,n-k){
        int MIN=INF,MINpos=0;
        rep(j,0,k){
            if(s[j]-'0'<MIN){MIN=s[j]-'0';MINpos=j;}
        }
        if(MIN||flag){
            putchar(s[MINpos]);
            flag=1;
        }
        k-=MINpos;
        s.erase(0,MINpos+1);
    }
    if(!flag)putchar('0');
    return 0;
}