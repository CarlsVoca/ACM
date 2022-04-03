#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];
string s[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    cin>>a[1]>>s[1];
    if(a[1]==0)a[1]=-1;
    per(i,n,2){
        cin>>a[i]>>s[i];
        if(a[i]==0)a[i]=-1;
    }
    int pos=1;
    rep(i,1,m){
        int t,k;
        cin>>t>>k;
        if(t==0)t=-1;
        pos=((pos+k*t*a[pos])%n+n-1)%n+1;
        // cout<<s[pos]<<endl;
    }
    cout<<s[pos]<<endl;
    return 0;
}