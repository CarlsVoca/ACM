#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

int main(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i+2<s.length();i++){
        if(s[i]=='Z'&&s[i+1]=='O'&&s[i+2]=='N')ans++;
    }
    printf("%d\n",ans);
    return 0;
}