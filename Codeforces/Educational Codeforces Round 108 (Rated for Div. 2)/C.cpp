#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=200005;

int u[maxn],s[maxn];
vector<int> vec[maxn];
LL ans[maxn],sum[maxn];

bool cmp(int a,int b){return a>b;}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)vec[i].clear(),ans[i]=0;
        rep(i,1,n)scanf("%d",&u[i]);
        rep(i,1,n)scanf("%d",&s[i]);
        rep(i,1,n){
            vec[u[i]].push_back(s[i]);
        }
        rep(i,1,n)sort(vec[i].begin(),vec[i].end(),cmp);
        rep(i,1,n){
            sum[0]=0;
            rep(j,0,(int)vec[i].size()-1){
                sum[j+1]=sum[j]+vec[i][j];
            }
            rep(j,1,vec[i].size()){
                ans[j]+=sum[vec[i].size()/j*j];
            }
        }
        rep(i,1,n)printf("%lld ",ans[i]);
        putchar('\n');
    }
    return 0;
}