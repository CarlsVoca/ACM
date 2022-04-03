#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    bool flag=1;
    for(int i=2;i<n;i++){
        if((s[i-2]-'A'+s[i-1]-'A'+26)%26==s[i]-'A')continue;
        else {flag=0;break;}
    }
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}