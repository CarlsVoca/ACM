#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=500005;

deque<char> q;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    bool rev=0;
    rep(i,0,n-1){
        if(s[i]!='R'){
            if(rev){
                if(!q.empty()&&q.front()==s[i])q.pop_front();
                else q.push_front(s[i]);
            }
            else{
                if(!q.empty()&&q.back()==s[i])q.pop_back();
                else q.push_back(s[i]);
            }
        }
        else rev^=1;
    }
    if(!rev){
        while(!q.empty()){
            putchar(q.front());
            q.pop_front();
        }
    }
    else{
        while(!q.empty()){
            putchar(q.back());
            q.pop_back();
        }    
    }
    putchar('\n');
    return 0;
}