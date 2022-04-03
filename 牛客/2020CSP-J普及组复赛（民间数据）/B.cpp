#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

namespace Functional_Treap{
    typedef pair<int,int> pii;
    struct Node{
        int l,r,key,val,size;
    }t[maxn];
    int root,num=0;
    inline int Rand(){
    	static int seed=703;
    	return seed=int(seed*48271LL%2147483647);
	}
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
    int rank(int x,int k){
        int ans=0,tmp=INF;
        while(k){
            if(x==t[k].val)tmp=min(tmp,ans+t[t[k].l].size+1);
            if(x<t[k].val)ans+=t[t[k].l].size+1,k=t[k].r;
            else k=t[k].l;
        }
        return tmp==INF?ans:tmp;
    }
    int find(int x,int k){
        while(1){
            if(t[t[k].l].size==x-1)return t[k].val;
            if(t[t[k].l].size>x-1)k=t[k].l;
            else x=x-t[t[k].l].size-1,k=t[k].r;
        }
    }
    void insert(int x){
        int k=rank(x,root);
        pii tmp=split(root,k);
        t[++num].val=x;
        t[num].key=Rand();
        t[num].size=1;
        root=merge(tmp.first,num);
        root=merge(root,tmp.second);
    }
}
using namespace Functional_Treap;

int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        insert(x);
        printf("%d ",find(max(1,(int)(i*w*0.01)),root));
    }
    return 0;
}