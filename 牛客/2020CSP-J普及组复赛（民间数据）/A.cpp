#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

vector<int> ans;

int main(){
    int n;
    scanf("%d",&n);
    per(i,30,1){
        if(n>=(1<<i))ans.push_back(1<<i),n-=(1<<i);
    }
    if(n)puts("-1");
    else{
        rep(i,0,(int)ans.size()-1)printf("%d ",ans[i]);
    }
    return 0;
}