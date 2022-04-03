#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string a,b;
        cin>>a>>b;
        a=' '+a;
        b=' '+b;
        int ans=0;
        rep(i,1,n){
            if(i==1){
                if(a[i]=='0'){
                    if(b[i]=='1'){
                        b[i]='0';
                        ans++;
                    }
                }
                else{
                    if(b[i+1]=='1'){
                        b[i+1]='0';
                        ans++;
                    }
                }
            }
            else if(i==n){
                if(a[i]=='0'){
                    if(b[i]=='1'){
                        b[i]='0';
                        ans++;
                    }
                }
                else{
                    if(b[i-1]=='1'){
                        b[i-1]='0';
                        ans++;
                    }
                }
            }
            else{
                if(a[i]=='0'){
                    if(b[i]=='1'){
                        b[i]='0';
                        ans++;
                    }
                }
                else{
                    if(b[i-1]=='1'){
                        b[i-1]='0';
                        ans++;
                    }
                    else if(b[i+1]=='1'){
                        b[i+1]='0';
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}