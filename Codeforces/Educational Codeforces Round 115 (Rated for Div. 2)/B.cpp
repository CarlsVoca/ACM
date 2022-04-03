#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1005;

int x[maxn][6];
int n;

bool check(int a,int b){
    bool flag=0;
    int cnt1=0,cnt2=0,cnt3=0;
    rep(i,1,n){
        if(x[i][a]==0&&x[i][b]==0){
            return 0;
        }
        if(x[i][a]==1&&x[i][b]==1){
            cnt1++;
        }
        else if(x[i][a]==1)cnt2++;
        else cnt3++;
    }
    if(abs(cnt2-cnt3)<=cnt1&&(n%2==0))return 1;
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n){
            rep(j,1,5){
                scanf("%d",&x[i][j]);
            }
        }
        bool flag=0;
        rep(i,1,5){
            rep(j,i+1,5){
                if(check(i,j)){
                    flag=1;
                    break;
                }
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}