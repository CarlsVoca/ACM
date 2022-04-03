#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

map<string,int> mp;

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int t,s;
        string name;
        cin>>t;
        if(t==1){
            cin>>name>>s;
            mp[name]=s;
            puts("OK");
        }
        else if(t==2){
            cin>>name;
            if(!mp.count(name))puts("Not found");
            else printf("%d\n",mp[name]);
        }
        else if(t==3){
            cin>>name;
            if(!mp.count(name))puts("Not found");
            else{
                mp.erase(name);
                puts("Deleted successfully");
            }
        }
        else printf("%d\n",mp.size());
    }
    return 0;
}