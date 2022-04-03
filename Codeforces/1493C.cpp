#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int cnt[maxn][30];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        string s;
        cin>>s;
        s='0'+s;
        rep(i,1,n){
            rep(j,0,25){
                cnt[i][j]=cnt[i-1][j];
            }
            cnt[i][s[i]-'a']++;
        }
        bool flag=1;
        rep(i,0,25)if(cnt[n][i]%k){flag=0;break;}
        if(flag){cout<<s.substr(1)<<endl;continue;}
        per(i,n,1){
            rep(j,s[i]-'a'+1,25){
                cnt[i][s[i]-'a']--;
                cnt[i][j]++;
                int ned[30],sum=0;
                rep(l,0,25){
                    if(cnt[i][l]%k)ned[l]=(cnt[i][l]/k+1)*k-cnt[i][l],sum+=ned[l];
                    else ned[l]=0;
                }
                cnt[i][s[i]-'a']++;
                cnt[i][j]--;
                if(sum>n-i||(n-i-sum)%k)continue;
                ned[0]+=n-i-sum;
                string ans=s.substr(1,i-1);
                ans+=j+'a';
                rep(l,0,25){
                    rep(o,1,ned[l])ans+=l+'a';
                }
                flag=1;
                cout<<ans<<endl;
                break;
            }
            if(flag)break;
        }
        if(flag)continue;
        else puts("-1");
    }
    return 0;
}