#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=15;

int a[maxn],b[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string s;
        cin>>s;
        rep(i,1,10){
            if(s[i-1]=='0')a[i]=0;
            else if(s[i-1]=='1')a[i]=1;
            else a[i]=2;
        }
        int ans=10;
        rep(i,0,(1<<10)-1){
            rep(j,1,10){
                b[j]=((i&(1<<j-1))?1:0);
            }
            bool flag=1;
            rep(j,1,10){
                if(a[j]!=b[j]&&a[j]!=2){flag=0;break;}
            }
            if(!flag)continue;
            int cnt1=0,res1=5,cnt2=0,res2=5;
            rep(j,1,10){
                if(j&1)cnt1+=b[j],res1--;
                else cnt2+=b[j],res2--;
                if(cnt1+res1<cnt2||cnt2+res2<cnt1){ans=min(ans,j);break;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}