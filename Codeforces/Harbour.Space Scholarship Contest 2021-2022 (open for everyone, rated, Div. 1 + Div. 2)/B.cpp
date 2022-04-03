#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=505;

int n,m;
string s,t;

bool dfs(int x,int y,bool flag){
    if(y==m-1)return 1;
    y++;
    if(flag==1){
        if(x==0)return 0;
        x--;
        if(s[x]==t[y])return dfs(x,y,1);
        else return 0;
    }
    else{
        bool fg=0;
        if(x!=n-1&&s[x+1]==t[y]){
            fg|=dfs(x+1,y,0);
        }
        if(x!=0&&s[x-1]==t[y]){
            fg|=dfs(x-1,y,1);
        }
        return fg;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cin>>s>>t;
        n=s.length();
        m=t.length();
        bool flag=0;
        rep(i,0,n-1){
            if(s[i]==t[0]){
                if(dfs(i,0,0)){flag=1;break;}
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}