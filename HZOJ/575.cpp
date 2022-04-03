#include<bits/stdc++.h>

using namespace std;

map<string,int> mp;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        int pg;
        cin>>s>>pg;
        mp[s]=pg;
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        cout<<mp[s]<<endl;
    }
    return 0;
}