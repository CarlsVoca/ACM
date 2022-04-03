#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int a[5];
    rep(i,1,3)scanf("%d",&a[i]);
    sort(a+1,a+4);
    string s;
    cin>>s;
    rep(i,0,2)printf("%d ",a[s[i]-'A'+1]);
    return 0;
}