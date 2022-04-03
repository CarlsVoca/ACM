#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=105;

struct Stu{
    string name;
    int y,m,d,id;
    bool operator < (const Stu &b)const{
        if(y!=b.y)return y<b.y;
        if(m!=b.m)return m<b.m;
        if(d!=b.d)return d<b.d;
        return id>b.id;
    }
}s[maxn];

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        s[i].id=i;
        cin>>s[i].name>>s[i].y>>s[i].m>>s[i].d;
    }
    sort(s+1,s+n+1);
    rep(i,1,n)cout<<s[i].name<<endl;
    return 0;
}