#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=150005;

struct Data{
    string name;
    int val,t;
    bool operator < (const Data& d)const{
        return val==d.val?t>d.t:val>d.val;
    }
    bool operator == (const Data& d)const{
        return val==d.val&&t==d.t;
    }
    bool operator > (const Data& d)const{
        return val==d.val?t<d.t:val<d.val;
    }
};

namespace Functional_Treap{
    typedef pair<int,int> pii;
    struct Node{
        int l,r,key;
        Data val;
        int size;
    }t[maxn];
    int root,num=1;
    void update(int x){
        t[x].size=t[t[x].l].size+t[t[x].r].size+1;
    }
    int merge(int r1,int r2){
        if(!r1||!r2)return r1+r2;
        if(t[r1].key<t[r2].key){
            return t[r1].r=merge(t[r1].r,r2),update(r1),r1;
        }
        else{
            return t[r2].l=merge(r1,t[r2].l),update(r2),r2;
        }
    }
    pii split(int rt,int k){
        if(!k)return mp(0,rt);
        int l=t[rt].l,r=t[rt].r;
        if(k==t[l].size)return t[rt].l=0,update(rt),mp(l,rt);
        if(k==t[l].size+1)return t[rt].r=0,update(rt),mp(rt,r);
        if(k<t[l].size){
            pii tmp=split(l,k);
            return t[rt].l=tmp.second,update(rt),mp(tmp.first,rt);
        }
        pii tmp=split(r,k-t[l].size-1);
        return t[rt].r=tmp.first,update(rt),mp(rt,tmp.second);
    }
    int rank(Data x,int k){
        int ans=0,tmp=INF;
        while(k){
            if(x==t[k].val)tmp=min(tmp,ans+t[t[k].l].size+1);
            if(x>t[k].val)ans+=t[t[k].l].size+1,k=t[k].r;
            else k=t[k].l;
        }
        return tmp==INF?ans:tmp;
    }
    Data find(int x,int k){
        while(1){
            if(t[t[k].l].size==x-1)return t[k].val;
            if(t[t[k].l].size>x-1)k=t[k].l;
            else x=x-t[t[k].l].size-1,k=t[k].r;
        }
    }
    void insert(Data x){
        int k=rank(x,root);
        pii tmp=split(root,k);
        t[++num].val=x;
        t[num].key=rand();
        t[num].size=1;
        root=merge(tmp.first,num);
        root=merge(root,tmp.second);
    }
    void del(Data x){
        int k=rank(x,root);
        pii t1=split(root,k);
        pii t2=split(t1.first,k-1);
        root=merge(t2.first,t1.second);
    }
}
using namespace Functional_Treap;

int cnt=0;
map<string,int> T,Val;

int main(){
    srand(time(0));
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        string name;
        int val;
        cin>>name>>val;
        T[name]=i;Val[name]=val;
        if(i==1){
            t[root=1].val=(Data){name,val,i};
            t[root].size=1;
            t[root].key=rand();
        }
        else insert((Data){name,val,i});
        cnt++;
    }
    // puts("Carls");
    int tt=n;
    int m;
    scanf("%d",&m);
    rep(i,1,m){
        char op;
        string name;
        int val;
        cin>>op>>name;
        if(op=='+'){
            cin>>val;
            Data inn=(Data){name,val,++tt};
            T[name]=tt;Val[name]=val;
            if(cnt/5==(cnt+1)/5){
                if(cnt/5==0){
                    cout<<name<<" is not working now."<<endl;
                }
                else{
                    Data nw=find(cnt/5,root);
                    if(inn<nw){
                        cout<<name<<" is working hard now."<<endl;
                        cout<<nw.name<<" is not working now."<<endl;
                    }
                    else cout<<name<<" is not working now."<<endl;
                }
            }
            else{
                Data nw=find((cnt+1)/5,root);
                if(inn<nw)cout<<name<<" is working hard now."<<endl;
                else{
                    cout<<name<<" is not working now."<<endl;
                    cout<<nw.name<<" is working hard now."<<endl;
                }
            }
            insert(inn);
            cnt++;
        }
        else{
            Data ott=(Data){name,Val[name],T[name]};
            if(cnt/5==(cnt-1)/5){
                if(cnt/5!=0){
                    Data nw=find(cnt/5,root);
                    if(ott<nw||ott==nw){
                        cout<<find(cnt/5+1,root).name<<" is working hard now."<<endl;
                    }
                }
            }
            else{
                Data nw=find(cnt/5,root);
                if(ott>nw)cout<<nw.name<<" is not working now."<<endl;
            }
            del(ott);
            cnt--;
        }
    }
    return 0;
}