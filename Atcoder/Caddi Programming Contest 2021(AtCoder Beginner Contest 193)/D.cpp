#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int cnt[2][15];

int cul(int k){
    int res=0;
    rep(i,1,9){
        res+=i*pow(10,cnt[k][i]);
    }
    return res;
}

int main(){
    string a,b;
    LL k;
    cin>>k>>a>>b;
    rep(i,0,3)cnt[0][a[i]-'0']++;
    rep(i,0,3)cnt[1][b[i]-'0']++;
    LL tot=0,res=0;
    rep(i,1,9){
        if(cnt[0][i]+cnt[1][i]+1>k)continue;
        rep(j,1,9){
            if(cnt[1][j]+cnt[0][j]+1>k)continue;
            if(i==j&&cnt[0][i]+cnt[1][j]+2>k)continue;
            tot+=(k-cnt[0][i]-cnt[1][i])*(k-cnt[1][j]-cnt[0][j])-(i==j?(k-cnt[1][j]-cnt[0][j]):0);
            cnt[0][i]++;
            cnt[1][j]++;
            if(cul(0)>cul(1)){
                cnt[0][i]--;
                cnt[1][j]--;
                res+=(k-cnt[0][i]-cnt[1][i])*(k-cnt[1][j]-cnt[0][j])-(i==j?(k-cnt[1][j]-cnt[0][j]):0);
            }
            else{
                cnt[0][i]--;
                cnt[1][j]--;    
            }
        }
    }
    // printf("debug:%d %d\n",tot,res);
    printf("%lf\n",res*1.0/tot);
    return 0;
}