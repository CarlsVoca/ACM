#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=15;

int a[maxn];

int main(){
    int sum=0;
    rep(i,0,9){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    string ans="";
    rep(i,1,sum/2){
        if(i==1){
            rep(j,1,9){
                if(a[j]>=2){
                    ans=ans+(char)(j+'0');
                    a[j]-=2;
                    break;
                }
            }
        }
        else{
            rep(j,0,9){
                if(a[j]>=2){
                    ans=ans+(char)(j+'0');
                    a[j]-=2;
                    break;
                }
            }
        }
    }
    string ans2="";
    per(i,(LL)ans.length()-1,0)ans2=ans2+ans[i];
    if(sum%2){
        rep(i,0,9){
            if(a[i]){
                a[i]--;
                ans=ans+(char)(i+'0')+ans2;
                break;
            }
        }
    }
    else ans=ans+ans2;
    if(ans.length()==sum)cout<<ans<<endl;
    else puts("-1");
    return 0;
}