#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

vector<string> v;

int main(){
    freopen("p022_names.txt","r",stdin);
    char c=getchar();
    // printf("%c",c);
    while(c!=EOF){
        string s="";
        while(c=='"'||c==',')c=getchar();
        // printf("%c",c);
        while(c>='A'&&c<='Z'){
            s+=c;
            c=getchar();
        }
        v.push_back(s);
    }
    LL ans=0;
    sort(v.begin(),v.end());
    // rep(i,0,(int)v.size()-1)cout<<v[i]<<endl;
    // cout<<v[938]<<endl;
    rep(i,1,(int)v.size()-1){
        int res=0;
        rep(j,0,(int)v[i].length()-1){
            res+=v[i][j]-'A'+1;
        }
        ans+=res*i;
    }
    printf("%lld\n",ans);
    return 0;
}