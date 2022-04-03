#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int sum1=0,sum2=0,cnt1=0,cnt2=0;
    rep(i,1,n){
        if(i%k==0)sum1+=i,cnt1++;
        else sum2+=i,cnt2++;
    }
    printf("%.1lf %.1lf\n",sum1*1.0/cnt1,sum2*1.0/cnt2);
    return 0;
}