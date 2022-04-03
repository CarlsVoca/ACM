#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        if(n<4)puts("NO");
        else{
            if(s[n-4]=='2'&&s[n-3]=='0'&&s[n-2]=='2'&&s[n-1]=='0')puts("YES");
            else if(s[0]=='2'&&s[n-3]=='0'&&s[n-2]=='2'&&s[n-1]=='0')puts("YES");
            else if(s[0]=='2'&&s[1]=='0'&&s[n-2]=='2'&&s[n-1]=='0')puts("YES");
            else if(s[0]=='2'&&s[1]=='0'&&s[2]=='2'&&s[n-1]=='0')puts("YES");
            else if(s[0]=='2'&&s[1]=='0'&&s[2]=='2'&&s[3]=='0')puts("YES");
            else puts("NO");
        }
    }
    return 0;
}