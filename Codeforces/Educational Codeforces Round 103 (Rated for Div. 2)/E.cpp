#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

struct Edge{
    int u,v,nxt;
}e[maxn*30];

int nume=0,last[maxn];
int de[maxn];

inline void add_edge(int u,int v){
    de[v]++;
    e[++nume]=(Edge){u,v,last[u]};
    last[u]=nume;
}

int n,m,k;
string ss[maxn];

namespace Topo_Sort{
    int topo[maxn],num=0;
    queue<int>q;
    bool do_main(){
        for(int i=1;i<=n;i++){
            if(!de[i])q.push(i);
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            topo[++num]=u;
            for(int i=last[u];i;i=e[i].nxt){
                int v=e[i].v;
                if(--de[v]==0)q.push(v);
            }
        }
        if(num!=n)return 1;
        else return 0;
    }
}
using namespace Topo_Sort;

struct Node{
    int id,ch[35];
}t[maxn<<2];
int sz=1;

void insert(string s,int x){
    int u=1;
    rep(i,0,k-1){
        if(t[u].ch[s[i]-'_'])u=t[u].ch[s[i]-'_'];
        else u=t[u].ch[s[i]-'_']=++sz;
    }
    t[u].id=x;
}

void query(int u,string s,int x){
    if(s==""){
        // printf("debug:%d %d\n",x,t[u].id);
        if(x!=t[u].id)add_edge(x,t[u].id);
        return;
    }
    if(t[u].ch[s[0]-'_'])query(t[u].ch[s[0]-'_'],s.substr(1),x);
    if(t[u].ch[0])query(t[u].ch[0],s.substr(1),x);
}

bool match(string a,string b){
    rep(i,0,k-1){
        if(a[i]==b[i]||a[i]=='_')continue;
        else return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    rep(i,1,n){
        cin>>ss[i];
        insert(ss[i],i);
    }
    bool flag=1;
    rep(i,1,m){
        string s;
        int x;
        cin>>s>>x;
        if(!match(ss[x],s)){flag=0;continue;}
        query(1,s,x);
    }
    if(do_main()||!flag)puts("NO");
    else{
        puts("YES");
        rep(i,1,num)printf("%d ",topo[i]);
    }
    return 0;
}