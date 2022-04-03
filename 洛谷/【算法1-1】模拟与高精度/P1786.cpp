#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=120;

struct Q{
    string name,s;
    int id,v,l;
    bool operator < (const Q &b)const{
        if(v!=b.v)return v>b.v;
        if(l!=b.l)return l>b.l;
        if(id!=b.id)return id<b.id;
        return name<b.name;
    }
}q[maxn];

bool cmp1(Q a,Q b){
    if(a.v!=b.v)return a.v>b.v;
    return a.id<b.id;
}

int f(string s){
    if(s=="BangZhu")return 7;
    if(s=="FuBangZhu")return 6;
    if(s=="HuFa")return 5;
    if(s=="ZhangLao")return 4;
    if(s=="TangZhu")return 3;
    if(s=="JingYing")return 2;
    return 1;
}

bool cmp2(Q a,Q b){
    if(a.s!=b.s)return f(a.s)>f(b.s);
    if(a.l!=b.l)return a.l>b.l;
    return a.id<b.id;
}


string judge(int id){
    if(id==1)return "BangZhu";
    if(id<=3)return "FuBangZhu";
    if(id<=5)return "HuFa";
    if(id<=9)return "ZhangLao";
    if(id<=16)return "TangZhu";
    if(id<=41)return "JingYing";
    return "BangZhong";
}

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        q[i].id=i;
        cin>>q[i].name>>q[i].s>>q[i].v>>q[i].l;
    }
    sort(q+4,q+n+1,cmp1);
    rep(i,4,n)q[i].s=judge(i);
    sort(q+1,q+n+1,cmp2);
    rep(i,1,n)cout<<q[i].name<<" "<<q[i].s<<" "<<q[i].l<<endl;
    return 0;
}