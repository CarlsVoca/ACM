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
        int l1=0,l2=0;
        string s;
        cin>>s;
        int n=s.length();
        int ans=0;
        rep(i,0,n-1){
            if(s[i]=='(')l1++;
            else if(s[i]=='[')l2++;
            else if(s[i]==')'){
                if(l1)ans++,l1--;
            }
            else if(s[i]==']'){
                if(l2)ans++,l2--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}