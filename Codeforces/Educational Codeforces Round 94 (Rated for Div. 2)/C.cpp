#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int ans[maxn];
char tmp[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string s;
        int x;
        cin>>s>>x;
        int n=s.length();
        rep(i,0,n-1)ans[i]=0;
        rep(i,0,n-1){
            if(i<x&&i+x<n)ans[i]=s[i+x]-'0';
            else if(i+x>=n&&i-x>=0)ans[i]=s[i-x]-'0';
            else if(i+x<n&&i-x>=0)ans[i]=min(s[i+x]-'0',s[i-x]-'0');
        }
        bool flag=1;
        rep(i,0,n-1){
            if(i>=x&&ans[i-x]==1)tmp[i]='1';
            else if(i+x<n&&ans[i+x]==1)tmp[i]='1';
            else tmp[i]='0';
        }
        rep(i,0,n-1)if(s[i]!=tmp[i]){flag=0;break;}
        if(!flag)puts("-1");
        else{
            rep(i,0,n-1)printf("%d",ans[i]);
            putchar('\n');
        }
/*        
        rep(i,0,n-1)printf("%d",ans[i]);
        putchar('\n');
        rep(i,0,n-1)printf("%c",tmp[i]);
        putchar('\n');
*/
    }
    return 0;
}