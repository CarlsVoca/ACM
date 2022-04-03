#include<cstring>
#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

int f[maxn],p[maxn];

void Pre(int n){
    rep(i,1,n)f[i]=i,p[i]=0;
}

int Find(int x){
    if(x==f[x])return x;
    int tmp=f[x];
    f[x]=Find(f[x]);
    p[x]=(p[x]+p[tmp])%3;
    return f[x];
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    Pre(n);
    int ans=0;
    rep(i,1,k){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(a>n||b>n){ans++;continue;}
        else if(t==2&&a==b){ans++;continue;}
        int fa=Find(a),fb=Find(b);
        if(fa!=fb){
            f[fa]=fb;
            p[fa]=((3-p[a]+t-1+p[b])%3+3)%3;
        }
        else if((p[a]+3-p[b])%3!=t-1)ans++;
    }
    printf("%d\n",ans);
    return 0;
}