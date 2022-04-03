#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

stack<int> sta;
int p[maxn];

int main(){
    memset(p,-1,sizeof(p));
    string s;
    cin>>s;
    int n=s.length();
    rep(i,0,n-1){
        if(s[i]=='('||s[i]=='[')sta.push(i);
        else{
            if(s[i]==')'&&!sta.empty()&&s[sta.top()]=='('){
                p[i]=sta.top();
                p[sta.top()]=i;
                sta.pop();
            }
            else if(s[i]==']'&&!sta.empty()&&s[sta.top()]=='['){
                p[i]=sta.top();
                p[sta.top()]=i;
                sta.pop();
            }
        }
    }
    rep(i,0,n-1){
        if(p[i]!=-1)putchar(s[i]);
        else{
            if(s[i]=='('||s[i]==')')printf("()");
            else printf("[]");
        }
    }
    return 0;
}