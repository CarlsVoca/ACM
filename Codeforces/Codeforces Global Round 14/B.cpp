#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const double eps=1e-4;

int dcmp(double x,double y){return fabs(x-y)<eps?0:(x<y?-1:1);}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(n&1){puts("NO");continue;}
        double sq=sqrt(1.0*n);
        if(dcmp(sq,floor(sq+0.5))==0||dcmp(sq/sqrt(2.0),floor(sq/sqrt(2.0)+0.5))==0)puts("YES");
        else puts("NO");
    }
    return 0;
}