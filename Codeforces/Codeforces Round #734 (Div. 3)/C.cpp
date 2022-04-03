#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=200005;

struct Data{
    string s;
    int val;
    bool operator < (const Data d)const{
        return val>d.val;
    }
}d[maxn];

int n;
int solve(char ch){
    rep(i,1,n){
        d[i].val=0;
        rep(j,0,(int)d[i].s.length()-1){
            if(d[i].s[j]==ch)d[i].val++;
            else d[i].val--;
        }
    }
    sort(d+1,d+n+1);
    int rest=d[1].val;
    if(rest<=0)return 0;
    int res=1;
    rep(i,2,n){
        if(rest+d[i].val>0)rest+=d[i].val,res++;
        else return res;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n)cin>>d[i].s;
        int ans=0;
        ans=max(ans,solve('a'));
        // printf("'a':%d\n",solve('a'));
        ans=max(ans,solve('b'));
        ans=max(ans,solve('c'));
        ans=max(ans,solve('d'));
        ans=max(ans,solve('e'));
        printf("%d\n",ans);
    }
    return 0;
}