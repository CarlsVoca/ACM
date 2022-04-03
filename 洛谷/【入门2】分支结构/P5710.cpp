#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int x;
    scanf("%d",&x);
    bool f1=((x%2)==0),f2=(x>4&&x<=12);
    printf("%d %d %d %d\n",f1&&f2?1:0,f1||f2?1:0,f1^f2?1:0,f1|f2?0:1);
    return 0;
}