#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

bool judge(string s){
    rep(i,0,s.length()/2){
        if(s[i]!=s[s.length()-1-i])return 0;
    }
    return 1;
}

int f(char c){
    if(c>='0'&&c<='9')return c-'0';
    else return 10+c-'A';
}
char g(int x){
    if(x<=9)return x+'0';
    else return x-10+'A';
}

int main(){
    int n;
    string m;
    cin>>n>>m;
    bool flag=0;
    rep(i,0,30){
        if(judge(m)){
            printf("STEP=%d\n",i);
            return 0;
        }
        string tmp=m;
        reverse(tmp.begin(),tmp.end());
        int nxt=0;
        per(j,m.length()-1,0){
            int sum=f(m[j])+f(tmp[j])+nxt;
            m[j]=g(sum%n);
            nxt=sum/n;
        }
        if(nxt)m=g(nxt)+m;
        // printf("Debug:");
        // cout<<m<<endl;
    }
    puts("Impossible!");
    return 0;
}