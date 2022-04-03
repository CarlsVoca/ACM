#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

map<LL,bool> mp;

int main(){
    LL n;
    cin>>n;
    LL cnt=0;
    rep(i,2,100000){
        LL tmp=i;
        tmp*=i;
        if(tmp>n)break;
        while(tmp<=n){
            if(!mp.count(tmp)){
                mp[tmp]=1;
                cnt++;
            }
            tmp*=i;
        }
    }
    // cout<<n<<" "<<cnt<<endl;
    cout<<n-cnt<<endl;
    return 0;
}