#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef pair<int,string> pis;

map<string,int> t;
map< pis,vector<string> > mp;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        string a,b;
        cin>>a>>b;
        if(!t.count(a))t[a]=i;
        mp[pis(t[a],a)].push_back(b);
    }
    for(auto p=mp.begin();p!=mp.end();++p){
        cout<<(p->first.second);
        for(auto q=(p->second).begin();q!=(p->second).end();++q){
            cout<<' '<<(*q);
        }
        cout<<endl;
    }
    return 0;
}