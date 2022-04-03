#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

map<string,set<string>> mp;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        string a,b;
        cin>>a>>b;
        if(mp[a].count(b))puts("NO");
        else{
            puts("YES");
            mp[a].insert(b);
        }
    }
    return 0;
}