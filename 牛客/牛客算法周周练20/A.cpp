#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;
const int maxm=105;

string a[maxn],b[maxm];;
int pos[maxm];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n)cin>>a[i];
    rep(i,1,m)cin>>b[i];
    rep(i,1,n){
        memset(pos,0,sizeof(pos));
        int res=0;
        rep(j,0,a[i].length()-1){
            rep(k,1,m){
                if(pos[k]<b[k].length()&&a[i][j]==b[k][pos[k]])pos[k]++;
            }
        }
        rep(j,1,m)if(pos[j]==b[j].length())res++;
        printf("%d\n",res);
    }
    return 0;
}