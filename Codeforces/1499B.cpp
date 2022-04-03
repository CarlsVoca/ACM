#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string s;
        cin>>s;
        int n=s.length();
        bool flag1=0,flag=1;
        rep(i,0,n-2){
            if(s[i]=='1'&&s[i+1]=='1')flag1=1;
            if(s[i]=='0'&&s[i+1]=='0'&&flag1==1)flag=0;
        }
        if(!flag)puts("NO");
        else puts("YES");
    }
    return 0;
}