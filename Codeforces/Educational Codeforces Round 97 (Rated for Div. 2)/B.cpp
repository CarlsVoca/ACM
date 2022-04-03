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
        s=s+s;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i]==s[i-1])ans++;
        }
        printf("%d\n",ans/2);
    }
    return 0;
}