#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

vector<LL> v[2];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        v[0].clear();v[1].clear();
        int n;
        scanf("%d",&n);
        rep(i,1,2*n){
            LL x,y;
            scanf("%lld%lld",&x,&y);
            if(x==0)v[0].push_back(abs(y));
            else v[1].push_back(abs(x));
        }
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        double ans=0;
        rep(i,0,n-1)ans+=sqrt(v[0][i]*v[0][i]+v[1][i]*v[1][i]);
        printf("%.10lf\n",ans);
    }
    return 0;
}