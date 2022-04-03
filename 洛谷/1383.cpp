#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=100005;

namespace Faction_Segment_Tree{
	struct Node{
		int ls,rs,sum;
        char ch;
	}t[maxn*40];
	int sz=0;
	int Update(int pre,int l,int r,int x,int k,char ch){
		int now=++sz;
		t[now]=t[pre];t[now].sum+=k;t[now].ch=ch;
		if(l<r){
			int mid=l+r>>1;
			if(x<=mid)t[now].ls=Update(t[pre].ls,l,mid,x,k,ch);
			else t[now].rs=Update(t[pre].rs,mid+1,r,x,k,ch);
		}
		return now;
	}
	int L,R,ll,rr;
	int Query(int l,int r,int k){
		if(l==r)return t[R].ch;
		int suml=0,sumr=0;
		suml+=t[t[L].ls].sum;
		sumr+=t[t[R].ls].sum;
		int del=sumr-suml;
		int mid=l+r>>1;
		if(k<=del){
			L=t[L].ls;
			R=t[R].ls;
			return Query(l,mid,k);
		}
		else{
			L=t[L].rs;
			R=t[R].rs;
			return Query(mid+1,r,k-del);
		}
	}
}
using namespace Faction_Segment_Tree;

int T[maxn],cnt[maxn],id=0;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        char opt;
        cin>>opt;
        if(opt=='T'){
            id++;
            char x;
            cin>>x;
            T[id]=Update(T[id-1],1,n,cnt[id-1]+1,1,x);
            cnt[id]=cnt[id-1]+1;
        }
        else if(opt=='U'){
            id++;
            int x;
            cin>>x;
            T[id]=T[id-x-1];
            cnt[id]=cnt[id-x-1];
        }
        else{
            int x;
            cin>>x;
            R=T[id];
            printf("%c\n",Query(1,n,x));
        }
    }
    return 0;
}