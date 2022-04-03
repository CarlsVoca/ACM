#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

map< string,vector<int> > mp;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        int l;
        scanf("%d",&l);
        rep(j,1,l){
            string s;
            cin>>s;
            if(!mp.count(s)||mp[s][mp[s].size()-1]!=i)mp[s].push_back(i);
        }
    }
    int m;
    scanf("%d",&m);
    rep(i,1,m){
        string s;
        cin>>s;
        if(!mp.count(s)){putchar('\n');continue;}
        // sort(mp[s].begin(),mp[s].end());
        // unique(mp[s].begin(),mp[s].end());
        rep(j,0,mp[s].size()-1){
            // if(j==0||mp[s][j]>mp[s][j-1])printf("%d ",mp[s][j]);
            // else break;
            printf("%d ",mp[s][j]);
        }
        putchar('\n');
    }
    return 0;
}