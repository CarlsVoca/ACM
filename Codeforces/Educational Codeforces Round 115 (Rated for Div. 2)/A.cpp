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
        string a,b;
        cin>>a>>b;
        bool flag=1;
        rep(i,0,(int)a.length()-1){
            if(a[i]==b[i]&&a[i]=='1'){
                flag=0;
                break;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}