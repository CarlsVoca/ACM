#include<cstring>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=50005;

int f[maxn],p[maxn];

void Pre(int n){
    rep(i,0,n-1)f[i]=i,p[i]=0;
}

int Find(int x){
    if(x==f[x])return x;
    int tmp=f[x];
    f[x]=Find(f[x]);
    p[x]=(p[x]+p[tmp])%3;
    return f[x];
}

int a[maxn],b[maxn],t[maxn];
char c[maxn];

int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)==2){
        rep(i,1,k){
            scanf("%d%c%d",&a[i],&c[i],&b[i]);
            if(c[i]=='=')t[i]=1;
            else if(c[i]=='<')t[i]=2;
            else t[i]=3;
        }
        int ans=0,judge=0,pos=0;
        rep(l,0,n-1){
            Pre(n);
            bool flag=0;
            rep(i,1,k){
                if(a[i]==l||b[i]==l)continue;
                int fa=Find(a[i]),fb=Find(b[i]);
                if(fa!=fb){
                    f[fa]=fb;
                    p[fa]=((3-p[a[i]]+t[i]-1+p[b[i]])%3+3)%3;
                }
                else if((p[a[i]]+3-p[b[i]])%3!=t[i]-1){flag=1;pos=max(pos,i);break;}
            }
            if(flag)ans++;
            else judge=l;
        }
        if(ans==n)puts("Impossible");
        else if(ans==n-1){
            printf("Player %d can be determined to be the judge after %d lines\n",judge,pos);
        }
        else puts("Can not determine");
    }
    return 0;
}