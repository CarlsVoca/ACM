#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn],b[maxn];
bool vis[maxn];

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        stack<int> sta;
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n)scanf("%d",&b[i]);
        int top=1;
        bool flag=1;
        rep(i,1,n){
            while((sta.empty()||sta.top()!=b[i])&&top<=n)sta.push(a[top++]);
            if(!sta.empty()&&sta.top()==b[i])sta.pop();
            else{flag=0;break;}
        }
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}