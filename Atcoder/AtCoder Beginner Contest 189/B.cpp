#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1000005;
const long double eps=1e-6;

long double v[maxn],p[maxn];

int main(){
    int n;
    long double x;
    cin>>n>>x;
    rep(i,1,n)cin>>v[i]>>p[i];
    int ans=-1;
    long double sum=0;
    rep(i,1,n){
        sum+=v[i]*p[i]/100;
        if(fabs(sum-x)>eps&&sum>x){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}