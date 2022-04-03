#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n;
    scanf("%d",&n);
    int MAX=-INF,MIN=INF;
    double sum=0;
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        MAX=max(MAX,x);
        MIN=min(MIN,x);
        sum+=x;
    }
    sum-=MAX;sum-=MIN;
    printf("%.2lf\n",sum/(n-2));
    return 0;
}