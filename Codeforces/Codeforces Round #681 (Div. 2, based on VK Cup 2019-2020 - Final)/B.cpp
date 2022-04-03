#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int dp[maxn],seg[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,tot=0;
        scanf("%d%d",&a,&b);
        string s;
        cin>>s;
        int n=s.length(),l=-1,r=-1;
        rep(i,0,n-1)if(s[i]=='1'){l=i;break;}
        per(i,n-1,0)if(s[i]=='1'){r=i;break;}
        if(l==-1){puts("0");continue;}
        int cnt=0;
        rep(i,l,r){
            if(s[i]=='0')cnt++;
            else if(s[i]=='1'&&i!=l&&s[i-1]=='0'){
                seg[++tot]=cnt;
                cnt=0;
            }
        }
        int ans=(tot+1)*a;
        sort(seg+1,seg+tot+1);
        int res=ans;
        rep(i,1,tot){
            res-=a;res+=seg[i]*b;
            ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}