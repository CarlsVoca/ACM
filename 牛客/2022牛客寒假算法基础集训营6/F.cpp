#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

string s;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cin>>s;
        int k;
        cin>>k;
        int n=s.length();
        int ans=0;
        rep(i,0,n-1){
            if(s[i]=='+')ans++;
            else ans--;
        }
        if(abs(ans)>=2*k){
            cout<<abs(ans)-2*k<<endl;
        }
        else{
            if(abs(ans)&1)cout<<1<<endl;
            else{
                k-=abs(ans)/2;
                if(k&1)cout<<2<<endl;
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}