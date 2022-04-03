#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<int> v;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        v.clear();
        int n,k;
        scanf("%d%d",&n,&k);
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            int cnt=0;
            if(i!=0)cnt+=(s[i-1]=='1');
            if(i!=n-1)cnt+=(s[i+1]=='1');
            if(cnt==1)v.push_back(i);
        }
        for(int i=1;i<=k;i++){
            if(v.empty())break;
            for(int j=0;j<v.size();j++)s[v[j]]='1';
            v.clear();
            for(int j=0;j<n;j++){
                if(s[j]=='1')continue;
                int cnt=0;
                if(j!=0)cnt+=(s[j-1]=='1');
                if(j!=n-1)cnt+=(s[j+1]=='1');
                if(cnt==1)v.push_back(j);
            }
        }
        cout<<s<<endl;
    }
    return 0;
}