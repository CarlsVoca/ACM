#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=1e6+5;

namespace Fast_IO{
	void read(int &x){
		x=0;int flag=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;if(ch==EOF)return;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
		x*=flag;
	}
}
using namespace Fast_IO;

struct Q{
    int l,r,id;
}q[maxn];

int a[maxn],pre[maxn],ans[maxn];
int n;

namespace Binary_Indexed_Tree{
	int c[maxn];
	void Change(int x,int k){
		for(;x<=n;x+=x&-x)c[x]+=k;
	}
	int Query(int x){
		int res=0;
		for(;x;x-=x&-x)res+=c[x];
		return res;
	}
}
using namespace Binary_Indexed_Tree;

int main(){
    scanf("%d",&n);
    rep(i,1,n)read(a[i]);
    int m;
    scanf("%d",&m);
    rep(i,1,m){
        read(q[i].l);read(q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1,[](Q a,Q b){
        return a.r<b.r;
    });
    int pos=0;
    rep(i,1,m){
        while(pos<q[i].r){
            pos++;
            if(pre[a[pos]])Change(pre[a[pos]],-1);
            Change(pos,1);
            pre[a[pos]]=pos;
        }
        ans[q[i].id]=Query(q[i].r)-Query(q[i].l-1);
    }
    rep(i,1,m)printf("%d\n",ans[i]);
    return 0;
}