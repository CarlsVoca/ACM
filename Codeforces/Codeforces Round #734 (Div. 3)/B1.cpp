#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

int cnt[30];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        rep(i,0,25)cnt[i]=0;
        string s;
        cin>>s;
        int n=s.length();
        rep(i,0,n-1)cnt[s[i]-'a']++;
        int cnt1=0,cnt2=0,cnt3=0;
        rep(i,0,25){
            if(cnt[i]>=3)cnt3++;
            else if(cnt[i]==2)cnt2++;
            else if(cnt[i]==1)cnt1++;
        }
        int ans=2*(cnt3+cnt2);
        ans+=cnt1;
        if(cnt1&1)ans--;
        printf("%d\n",ans/2);
    }
    return 0;
}