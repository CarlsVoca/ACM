#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=2147483647;
const int maxn=10005;

namespace Splay{
	struct Node{
		int ch[2];
		int f,key,size,cnt,flip;
	}t[maxn];
	int sz,root;
	inline bool judge(int x){
		return t[t[x].f].ch[1]==x;
	}
	inline void update(int x){
		t[x].size=t[x].cnt+t[t[x].ch[0]].size+t[t[x].ch[1]].size;
	}
	inline void pushdown(int x){
    	if(t[x].flip){
			t[x].flip^=1;t[t[x].ch[0]].flip^=1;t[t[x].ch[1]].flip^=1;
			swap(t[x].ch[0],t[x].ch[1]);
		}
	}
	void rotate(int x){
		int f=t[x].f,ff=t[f].f;
		bool posx=judge(x),posf=judge(f);
		t[t[x].ch[posx^1]].f=f;t[f].ch[posx]=t[x].ch[posx^1];
		t[f].f=x;t[x].ch[posx^1]=f;
		t[x].f=ff;if(ff)t[ff].ch[posf]=x;
		update(f);update(x);
	}
	void splay(int x,int &tar){
		int tmp=t[tar].f;
		for(int i;(i=t[x].f)!=tmp;rotate(x)){
			if(t[i].f!=tmp)rotate(judge(x)==judge(i)?i:x);
		}
		tar=x;
	}
	void reset(int x,int f,int key){
		t[x].f=f;t[x].key=key;t[x].cnt=t[x].size=1;
	}
	void insert(int x){
		if(!root){reset(++sz,0,x);root=sz;return;}
		int now=root,f=0;
		while(1){
			if(x==t[now].key){t[now].cnt++;update(now);splay(now,root);return;}
			f=now;now=t[now].ch[t[now].key<x];
			if(!now){
				reset(++sz,f,x);
				t[f].ch[t[f].key<x]=sz;
				splay(sz,root);
				return;
			}
		}
	}
	int Rank(int &rt,int x){
		int now=rt,res=1;
		while(now){
			pushdown(now);
			if(x==t[now].key){res+=t[t[now].ch[0]].size;splay(now,rt);return res;}
			else if(x>t[now].key)res+=t[now].size-t[t[now].ch[1]].size,now=t[now].ch[1];
			else now=t[now].ch[0];
		}
		return res;
	}
	int find(int &rt,int x){
		int now=rt,cnt=0;
		while(now){
			pushdown(now);
			if(cnt+t[now].size-t[t[now].ch[1]].size>=x&&cnt+t[t[now].ch[0]].size<x)return splay(now,rt),t[now].key;
			else if(cnt+t[now].size-t[t[now].ch[1]].size<x)cnt+=t[now].size-t[t[now].ch[1]].size,now=t[now].ch[1];
			else now=t[now].ch[0];
		}
		return splay(now,rt),t[now].key;
	}
	int merge(int &left,int right){
		if(!left||!right)return left|right;
		find(left,t[left].size);
		t[left].ch[1]=right;
		t[right].f=left;
		update(left);
		return left;
	}
	pii split(int &rt,int k){
		if(!k)return mp(0,rt);
		find(rt,k);
		int left=rt,right=t[rt].ch[1];
		t[left].ch[1]=0;
		t[right].f=0;
		update(left);
		return mp(left,right);
	}
	void del(int x){
		int k=Rank(root,x);
		pii t1=split(root,k);
		pii t2=split(t1.first,k-1);
		if(!(--t[t2.second].cnt))root=merge(t2.first,t1.second);
		else{
			root=merge(t2.first,t2.second);
			root=merge(root,t1.second);
		}
	}
	int pre(int x){
        int res=-INF,now=root;
        while(now){
        	pushdown(now);
            if(t[now].key<x)res=max(res,t[now].key),now=t[now].ch[1];
            else now=t[now].ch[0];
		}
        return res;
    }
    int neg(int x){
        int res=INF,now=root;
        while(now){
        	pushdown(now);
            if(t[now].key>x)res=min(res,t[now].key),now=t[now].ch[0];
            else now=t[now].ch[1];
        }
        return res;
    }
    void reverse(int l,int r){
		pii p1=split(root,l-1);
		pii p2=split(p1.second,r-l+1);
		t[p2.first].flip^=1;
		root=merge(p2.first,p2.second);
		root=merge(p1.first,root);
	}
}
using namespace Splay;

int main(){
    int q;
    scanf("%d",&q);
    insert(INF);
    insert(-INF);
    while(q--){
        int t,x;
        scanf("%d%d",&t,&x);
        if(t==1)printf("%d\n",Rank(root,x)-1);
        else if(t==2)printf("%d\n",find(root,x+1));
        else if(t==3)printf("%d\n",pre(x));
        else if(t==4)printf("%d\n",neg(x));
        else insert(x);
    }
    return 0;
}