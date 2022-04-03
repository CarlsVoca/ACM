#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=3e5+5;

int a[maxn],cnt[maxn],tar[maxn];
bool vis[maxn];
vector<int> ans;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ans.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n)cnt[i]=0;
        rep(i,1,n){
            cnt[((a[i]+n)-i)%n]++;
        }
        rep(i,0,n-1){
            // printf("debug:%d %d\n",i,cnt[i]);
            if(n-cnt[i]-(n-cnt[i])/2>m)continue;
            rep(j,1,i)tar[j]=j+(n-i);
            rep(j,i+1,n)tar[j]=j-i;
            rep(j,1,n)vis[j]=0;
            // if(i==1){puts("here::");rep(j,1,n)printf("%d ",tar[j]);
            // putchar('\n');}
            int res=0;
            rep(j,1,n){
                if(vis[j])continue;
                int cnt=1,p=j,st=j;
                vis[p]=1;
                while(tar[a[p]]!=st){
                    cnt++;
                    p=tar[a[p]];
                    vis[p]=1;
                }
                res+=cnt-1;
                if(res>m)break;
                // if(i==1)printf("Carls:%d\n",res);
            }
            if(res<=m)ans.push_back((n-i)%n);
        }
        printf("%d ",ans.size());
        sort(ans.begin(),ans.end());
        rep(i,0,(int)ans.size()-1)printf("%d ",ans[i]);
        putchar('\n');
    }
    return 0;
}