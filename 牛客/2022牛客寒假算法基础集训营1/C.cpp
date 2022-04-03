#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

int a[maxn][5];
int pos[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
    }
    rep(i,1,n)pos[i]=i;
    int ans=0;
    rep(i,1,n){
        rep(j,1,3){
            if(a[i][j]){
                if(pos[i]-pos[i-j]<4){
                    int tmp=4-(pos[i]-pos[i-j]);
                    ans+=tmp;
                    rep(k,i,n){
                        pos[k]+=tmp;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}