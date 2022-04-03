#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int cnt=0,ans=0;
    string s;
    while(getline(cin,s)){
        if(s[0]=='+'){
            cnt++;
        }
        else if(s[0]=='-'){
            cnt--;
        }
        else{
            int len=0;
            for(int i=0;i<s.length();i++){
                if(s[i]==':')len=0;
                else len++;
            }
            ans+=len*cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}