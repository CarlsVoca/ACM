#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int st_min[maxn][18],st_max[maxn][18];
vector<int> ans;

int query_min(int l,int r){
    int k=log2(r-l+1);
    return min(st_min[l][k],st_min[r-(1<<k)+1][k]);
}
int query_max(int l,int r){
    int k=log2(r-l+1);
    return max(st_max[l][k],st_max[r-(1<<k)+1][k]);
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%d",&st_max[i][0]);
        st_min[i][0]=st_max[i][0];
    }
    for(int j=1;j<=20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st_min[i][j]=min(st_min[i][j-1],st_min[i+(1<<j-1)][j-1]);
            st_max[i][j]=max(st_max[i][j-1],st_max[i+(1<<j-1)][j-1]);
        }
    }
    int len=0;
    rep(i,1,n){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r>>1)+1;
            if(query_max(i,mid)-query_min(i,mid)<=k)l=mid;
            else r=mid-1;
        }
        if(l-i+1>len){
            len=l-i+1;
            ans.clear();
        }
        if(l-i+1==len){
            ans.push_back(i);
        }
    }
    printf("%d %d\n",len,(int)ans.size());
    rep(i,0,(int)ans.size()-1)printf("%d %d\n",ans[i],ans[i]+len-1);
    return 0;
}