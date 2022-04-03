#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=55;

map<double,bool> vis;
double a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        vis.clear();
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%lf",&a[i]);
        rep(i,1,n){
            rep(j,i+1,n){
                if(vis.count(a[j]-a[i]))continue;
                else vis[a[j]-a[i]]=1;
            }
        }
        printf("%d\n",vis.size());
    }
    return 0;
}