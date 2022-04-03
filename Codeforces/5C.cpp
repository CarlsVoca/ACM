#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;

stack<int> sta;
bool vis[maxn];

int main(){
    string s;
    cin>>s;
    int n=s.length();
    rep(i,0,n-1){
        if(s[i]=='(')sta.push(i);
        else if(s[i]==')'){
            if(sta.empty())continue;
            vis[i]=vis[sta.top()]=1;
            sta.pop();
        }
    }
    int cnt=0,len=0,ans=0;
    rep(i,0,n-1){
        if(vis[i]==0){
            if(len==ans)cnt++;
            else if(len>ans){
                ans=len;
                cnt=1;
            }
            len=0;
        }
        else{
            len++;
        }
    }
    if(len==ans)cnt++;
    else if(len>ans){
        ans=len;
        cnt=1;
    }
    len=0;
    printf("%d %d\n",ans,ans==0?1:cnt);
    return 0;
}