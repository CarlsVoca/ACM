#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

double f(char ch){
    if(ch>='0'&&ch<='9')return ch-'0';
    else return ch-'A'+10;
}

double turn(string s,int base){
    double res=0;
    int len=s.length();
    double r=1;
    per(i,len-1,0){
        res+=f(s[i])*r;
        r*=base;
    }
    return res;
}

int main(){
    string s;
    while(cin>>s){
        int n=s.length();
        int a,b,t,MIN=2;
        rep(i,0,n-1){
            if(s[i]=='+')b=i,t=1;
            else if(s[i]=='-')b=i,t=2;
            else if(s[i]=='*')b=i,t=3;
            else if(s[i]=='/')b=i,t=4;
            else if(s[i]=='=')a=i;
            else if(s[i]>='0'&&s[i]<='9')MIN=max(MIN,s[i]-'0'+1);
            else if(s[i]>='A'&&s[i]<='Z')MIN=max(MIN,s[i]-'A'+11);
        }
        int ans=-1;
        rep(i,MIN,16){
            if(t==1&&turn(s.substr(0,b),i)+turn(s.substr(b+1,a-b-1),i)==turn(s.substr(a+1),i)){ans=i;break;}
            else if(t==2&&turn(s.substr(0,b),i)-turn(s.substr(b+1,a-b-1),i)==turn(s.substr(a+1),i)){ans=i;break;}
            else if(t==3&&turn(s.substr(0,b),i)*turn(s.substr(b+1,a-b-1),i)==turn(s.substr(a+1),i)){ans=i;break;}
            else if(t==4&&turn(s.substr(0,b),i)/turn(s.substr(b+1,a-b-1),i)==turn(s.substr(a+1),i)){ans=i;break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}