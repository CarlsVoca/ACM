#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double p=(a+b+c)/2.0;
    printf("%.1lf\n",sqrt(p*(p-a)*(p-b)*(p-c)));
    return 0;
}