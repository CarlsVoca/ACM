#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

const int maxn=1005;

string s[maxn];

int main(){
    int n=0;
    while(getline(cin,s[++n]));
    int MAX=0;
    rep(i,1,n)MAX=max(MAX,(int)s[i].length());
    rep(i,0,MAX+1)putchar('*');putchar('\n');
    bool flag=0;
    rep(i,1,n-1){
        putchar('*');
        int l,r;
        l=r=(MAX-s[i].length())/2;
        if((MAX-s[i].length())&1){
            if(!flag)r++;
            else l++;
            flag=(!flag);
        }
        rep(j,1,l)putchar(' ');
        cout<<s[i];
        rep(j,1,r)putchar(' ');
        putchar('*');putchar('\n');
    }
    rep(i,0,MAX+1)putchar('*');putchar('\n');
    return 0;
}