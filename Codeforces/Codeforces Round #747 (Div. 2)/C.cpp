#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=3e5+5;

string s;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        char c;
        scanf("%d",&n);
        cin>>c;
        cin>>s;
        s=' '+s;
        bool flag=1;
        rep(i,1,n){
            if(s[i]!=c){
                flag=0;
                break;
            }
        }
        if(flag){
            puts("0");
            continue;
        }
        int ans=-1;
        rep(i,n/2+1,n){
            if(s[i]==c){
                ans=i;
                break;
            }
        }
        if(ans!=-1){
            printf("1\n%d\n",ans);
        }
        else{
            printf("2\n");
            rep(i,2,n-1){
                if(n%i){
                    printf("%d ",i);
                    break;
                }
            }
            printf("%d\n",n);
        }
    }
    return 0;
}