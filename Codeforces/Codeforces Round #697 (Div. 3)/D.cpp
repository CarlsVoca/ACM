#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

struct Data{
    int a,b;
    bool operator < (const Data &d)const{
        return a>d.a;
    }
}d[maxn];

vector<Data> v1,v2;

LL sum1[maxn],sum2[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        v1.clear();
        v2.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,n)scanf("%d",&d[i].a);
        rep(i,1,n)scanf("%d",&d[i].b);
        rep(i,1,n){
            if(d[i].b==1)v1.push_back(d[i]);
            else v2.push_back(d[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int s1=v1.size(),s2=v2.size();
        sum1[0]=sum2[0]=0;
        rep(i,0,s1-1){
            sum1[i+1]=sum1[i]+v1[i].a;
        }
        rep(i,0,s2-1){
            sum2[i+1]=sum2[i]+v2[i].a;
        }
        int ans=INF;
        rep(i,0,s1){
            if(sum1[i]+sum2[s2]<m)continue;
            ans=min(ans,i*1+2*(int)(lower_bound(sum2,sum2+s2+1,m-sum1[i])-sum2));
        }
        if(ans==INF)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}