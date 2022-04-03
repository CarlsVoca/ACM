#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

map<string,int> mp;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        string s;
        cin>>s;
        if(!mp.count(s)){
            mp[s]=1;
            puts("OK");
        }
        else{
            cout<<s<<mp[s]<<endl;
            mp[s]++;
        }
    }
    return 0;
}