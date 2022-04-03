#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=2005;

int a[maxn];
map<int,int> mp;
vector<pii> ans;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,2*n)scanf("%d",&a[i]);
        sort(a+1,a+2*n+1);
        bool tot=0;
        rep(i,1,2*n-1){
            ans.clear();
            mp.clear();
            rep(j,1,2*n)mp[a[j]]++;
            mp[a[i]]--;
            if(mp[a[i]]==0)mp.erase(a[i]);
            mp[a[2*n]]--;
            if(mp[a[2*n]]==0)mp.erase(a[2*n]);
            bool flag=1;
            int x=a[2*n];
            per(j,2*n-1,1){
                if(!mp.count(a[j]))continue;
                else{
                    mp[a[j]]--;
                    if(mp[a[j]]==0)mp.erase(a[j]);
                    if(!mp.count(x-a[j])){
                        flag=0;
                        break;
                    }
                    else{
                        ans.push_back(make_pair(x-a[j],a[j]));
                        mp[x-a[j]]--;
                        if(mp[x-a[j]]==0)mp.erase(x-a[j]);
                        x=a[j];
                    }
                }
            }
            if(flag){
                tot=1;
                puts("YES");
                printf("%d\n",a[i]+a[2*n]);
                printf("%d %d\n",a[i],a[2*n]);
                rep(j,0,(int)ans.size()-1){
                    printf("%d %d\n",ans[j].first,ans[j].second);
                }
                break;
            }
        }
        if(!tot)puts("NO");
    }
    return 0;
}