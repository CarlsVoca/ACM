#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=200005;

int vis[maxn];
int a[maxn],ans[maxn];
stack<int> sta;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        while(!sta.empty())sta.pop();
        int n;
        scanf("%d",&n);
        rep(i,1,n)ans[i]=vis[i]=0;
        rep(i,1,n)scanf("%d",&a[i]);
        int tmp1,tmp2,cnt=0,tot=0;
        rep(i,1,n){
            if(vis[a[i]]){
                cnt++;
                tmp1=vis[a[i]];
                tmp2=i;
            }
            vis[a[i]]=i;
        }
        if(cnt!=1){
            rep(i,1,n){
                if(vis[i])ans[vis[i]]=i,tot++;
                else sta.push(i);
            }
            int pre=0;
            rep(i,1,n){
                if(!ans[i]){
                    if(i!=sta.top()){
                        ans[i]=sta.top();
                        sta.pop();
                    }
                    else{
                        if(sta.size()!=1){
                            int tmp=sta.top();sta.pop();
                            ans[i]=sta.top();sta.pop();
                            sta.push(tmp);
                        }
                        else{
                            ans[i]=sta.top();sta.pop();
                            swap(ans[i],ans[pre]);
                        }
                    }
                    pre=i;
                }
            }
            printf("%d\n",tot);
            rep(i,1,n)printf("%d ",ans[i]);
        }
        else{
            printf("%d\n",n-1);
            int res;
            rep(i,1,n){
                if(vis[i])ans[vis[i]]=i;
                else res=i;
            }
            if(tmp1==res){
                ans[tmp1]=ans[tmp2];
                ans[tmp2]=res;
            }
            else ans[tmp1]=res;
            rep(i,1,n)printf("%d ",ans[i]);
        }
        putchar('\n');
    }
    return 0;
}