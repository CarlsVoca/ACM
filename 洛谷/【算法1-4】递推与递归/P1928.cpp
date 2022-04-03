#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=20005;

char s[maxn];
int p[maxn];

void print(int l,int r){
    rep(i,l,r){
        if(s[i]!='[')putchar(s[i]);
        else{
            int t=p[i];
            i++;
            int cnt=s[i]-'0';
            i++;
            if(s[i]>='0'&&s[i]<='9')cnt=cnt*10+s[i++]-'0';
            rep(k,1,cnt)print(i,t-1);
            i=t;
        }
    }
}

int sta[maxn],top=0;

int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    rep(i,1,n){
        if(s[i]=='[')sta[++top]=i;
        else if(s[i]==']'){
            p[sta[top]]=i;
            top--;
        }
    }    
    print(1,n);
    return 0;
}