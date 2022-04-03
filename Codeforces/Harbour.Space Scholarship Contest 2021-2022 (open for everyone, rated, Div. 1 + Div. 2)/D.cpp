#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

string s,t;
int n,m;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cin>>s>>t;
        n=s.length();
        m=t.length();
        bool flag=0;
        rep(pre,0,n-1){
            if(n-pre-m<0)break;
            if(s[pre]!=t[0]||(n-pre-m)%2==1)continue;
            int p1=pre+1,p2=1;
            while(p2!=m){
                while(p1<=n-1&&s[p1]!=t[p2])p1+=2;
                while(p1<=n-1&&p2<=m-1&&s[p1]==t[p2])p1++,p2++;
                if(p1>=n)break;
            }
            if(p2==m){flag=1;break;}
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}