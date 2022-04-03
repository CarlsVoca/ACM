#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int k;
    scanf("%d",&k);
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();
    string ans;
    int left=0;
    for(int p=1;;p++){
        if(p>n&&p>m){
            if(left){
                ans+='1';
            }
            break;
        }
        int x;
        if(p>n){
            x=left+(b[m-p]-'0');
            if(x>=k)left=1,x-=k;
            else left=0;
            ans+=x+'0';
        }
        else if(p>m){
            x=left+(a[n-p]-'0');
            if(x>=k)left=1,x-=k;
            else left=0;
            ans+=x+'0';
        }
        else{
            x=left+(b[m-p]-'0')+(a[n-p]-'0');
            if(x>=k)left=1,x-=k;
            else left=0;
            ans+=x+'0';
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}