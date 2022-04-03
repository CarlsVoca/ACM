#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int a,b,w;
    scanf("%d%d%d",&a,&b,&w);
    w*=1000;
    int tmp1=w/a,tmp2=ceil(w*1.0/b);
    if(tmp1*b<w)puts("UNSATISFIABLE");
    else{
        printf("%d %d\n",tmp2,tmp1);
    }
    return 0;
}