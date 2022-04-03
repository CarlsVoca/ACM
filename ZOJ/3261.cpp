#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;
const int maxn=10005;
const int maxm=20005;
const int maxq=50005;

int p[maxn],a[maxm],b[maxm],x[maxq],y[maxq],ans[maxq];
string s[maxq];
map<pii,bool> vis;
int f[maxn];

void Init(int n){
    rep(i,0,n-1)f[i]=i;
}

int Find(int x){
    return f[x]==x?x:f[x]=Find(f[x]);
}

int main(){
    int n,m,Q;
    bool first=1;
    while(scanf("%d",&n)==1){
        if(!first)putchar('\n');
        else first=0;
        Init(n);
        vis.clear();
        rep(i,0,n-1)scanf("%d",&p[i]);
        scanf("%d",&m);
        rep(i,1,m)scanf("%d%d",&a[i],&b[i]);
        scanf("%d",&Q);
        rep(i,1,Q){
            cin>>s[i];
            if(s[i]=="query")scanf("%d",&x[i]);
            else{
                scanf("%d%d",&x[i],&y[i]);
                vis[mp(x[i],y[i])]=vis[mp(y[i],x[i])]=1;
            }
        }
        rep(i,1,m){
            if(!vis.count(mp(a[i],b[i]))){
                int fx=Find(a[i]),fy=Find(b[i]);
                if(fx==fy)continue;
                else{
                    if(p[fx]==p[fy]){
                        if(fx>fy)f[fx]=fy;
                        else f[fy]=fx;
                    }
                    else if(p[fx]<p[fy])f[fx]=fy;
                    else f[fy]=fx;
                }
            }
        }
        per(i,Q,1){
            if(s[i]=="query"){
                int fx=Find(x[i]);
                if(p[fx]>p[x[i]])ans[i]=fx;
                else ans[i]=-1;
            }
            else{
                int fx=Find(x[i]),fy=Find(y[i]);
                if(fx==fy)continue;
                else{
                    if(p[fx]==p[fy]){
                        if(fx>fy)f[fx]=fy;
                        else f[fy]=fx;
                    }
                    else if(p[fx]<p[fy])f[fx]=fy;
                    else f[fy]=fx;
                }
            }
        }
        rep(i,1,Q)if(s[i]=="query")printf("%d\n",ans[i]);
    }
    return 0;
}