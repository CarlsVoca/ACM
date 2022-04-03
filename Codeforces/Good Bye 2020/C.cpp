#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string s;
        cin>>s;
        string tmp=s;
        int n=s.length();
        int ans1=0;
        rep(i,0,n-2){
            if(tmp[i]==tmp[i+1])ans1++,tmp[i+1]=0;
            else if(i>=1&&tmp[i-1]==tmp[i+1])ans1++,tmp[i+1]=0;
            // printf("debug:%d\n",ans1);
        }
        tmp=s;
        int ans2=0;
        per(i,n-1,1){
            if(tmp[i]==tmp[i-1])ans2++,tmp[i-1]=0;
            if(i<=n-2&&tmp[i-1]==tmp[i+1])ans2++,tmp[i-1]=0;
        }
        printf("%d\n",min(ans1,ans2));
    }
    return 0;
}