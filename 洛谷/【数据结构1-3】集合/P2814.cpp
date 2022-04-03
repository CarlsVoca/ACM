#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

namespace Union_Find{
    map<string,string> f;
    string Find(string x){
        return f[x]==x?x:f[x]=Find(f[x]);
    }
    void Union(string x,string y){
        string fx=Find(x),fy=Find(y);
        f[fx]=fy;
    }
}
using namespace Union_Find;

int main(){
    char ch;
    string s,fa;
    while(cin>>ch){
        if(ch=='$')break;
        cin>>s;
        if(!f.count(s))f[s]=s;
        if(ch=='#') fa=s;
        else if(ch=='+')Union(s,fa);
        else cout<<s<<' '<<Find(s)<<endl;
    }
    return 0;
}