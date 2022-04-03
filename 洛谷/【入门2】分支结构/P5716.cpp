#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int y,m;
    scanf("%d%d",&y,&m);
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)puts("31");
    else if(m==2){
        if(y%400==0||(y%100!=0&&y%4==0))puts("29");
        else puts("28");
    }
    else puts("30");
    return 0;
}