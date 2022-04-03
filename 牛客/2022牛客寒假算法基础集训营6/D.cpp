#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int cnt[30],mp[30];
string s,t;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        cin>>s>>t;
        memset(cnt,0,sizeof(cnt));
        memset(mp,-1,sizeof(mp));
        rep(i,0,m-1){
            mp[t[i]-'a']=i+1;
        }
        rep(i,0,n-1){
            if(mp[s[i]-'a']==-1)continue;
            else if(mp[s[i]-'a']==1)cnt[1]++;
            else{
                if(cnt[mp[s[i]-'a']-1]){
                    cnt[mp[s[i]-'a']-1]--;
                    cnt[mp[s[i]-'a']]++;
                }
            }
        }
        printf("%d\n",cnt[m]);
    }
    return 0;
}