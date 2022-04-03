#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

void dfs(int x,string ans,int pre){
    rep(i,pre,x/2){
        dfs(x-i,ans+(char)(i+'0')+'+',i);
    }
    if(ans!=""){
        ans+=x+'0';
        cout<<ans<<endl;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    dfs(n,(string)"",1);
    return 0;
}