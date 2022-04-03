#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const double eps=1e-9;

int a=0,b=0;

int main(){
    string s;
    char ch;
    cin>>s;s+='=';
    int pos=0;
    while(s[pos]!='='){
        int res=0;
        int flag=1;
        if(s[pos]=='-')flag=-1,pos++;
        else if(s[pos]=='+')pos++;
        while(s[pos]>='0'&&s[pos]<='9')res=res*10+s[pos++]-'0';
        if(s[pos]>='a'&&s[pos]<='z')ch=s[pos],a+=(res==0?1:res)*flag,pos++;
        else b+=res*flag;
    }
    pos++;
    while(s[pos]!='='){
        int res=0;
        int flag=1;
        if(s[pos]=='-')flag=-1,pos++;
        else if(s[pos]=='+')pos++;
        while(s[pos]>='0'&&s[pos]<='9')res=res*10+s[pos++]-'0';
        if(s[pos]>='a'&&s[pos]<='z')ch=s[pos],a-=(res==0?1:res)*flag,pos++;
        else b-=res*flag;
    }
    double ans=-b*1.0/a;
    if(fabs(ans-0)<eps)ans=0;
    printf("%c=%.3lf\n",ch,ans);
    return 0;
}