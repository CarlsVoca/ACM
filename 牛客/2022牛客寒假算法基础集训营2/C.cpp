#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    LL a,b,x;
    cin>>x>>a>>b;
    string s;
    cin>>s;
    int n=s.length();
    int ans=0;
    rep(i,0,n-1){
        if(x<a){
            x+=b;
            continue;
        }
        if(s[i]=='1'){
            x-=a;
            ans++;
        }
        else{
            x+=b;
        }
    }
    printf("%d\n",ans);
    return 0;
}