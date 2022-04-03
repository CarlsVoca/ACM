#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<ctime>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=10005;

int f[maxn],p[maxn];

void Init(int n){
    rep(i,1,n)f[i]=i,p[i]=0;
}

int Find(int x){
    if(x==f[x])return x;
    int tmp=f[x];
    f[x]=Find(tmp);
    p[x]=p[x]^p[tmp];
    return f[x];
}

int l[maxn],r[maxn];

int T[maxn];
void lisan(int n){
    rep(i,1,n){T[i]=l[i];T[i+n]=r[i];}
    sort(T+1,T+2*n+1);
    int m=unique(T+1,T+2*n+1)-T-1;
    // printf("debug:m=%d\n",m);
    rep(i,1,n){l[i]=lower_bound(T+1,T+m+1,l[i])-T;r[i]=lower_bound(T+1,T+m+1,r[i])-T;}
}

char s[maxn][5];

int main(){
    int L,Q;
    scanf("%d%d",&L,&Q);
    rep(i,1,Q){scanf("%d%d%s",&l[i],&r[i],s[i]);l[i]--;}
    // rep(i,1,Q)printf("%s\n",s[i]);
    // clock_t beg,fin;
    // beg=clock();
    lisan(Q);
    Init(2*Q);
    int ans=-1;
    rep(i,1,Q){
        int fx=Find(l[i]),fy=Find(r[i]);
        if(fx!=fy){
            f[fx]=fy;
            if(s[i][0]=='e')p[fx]=p[l[i]]^p[r[i]];
            else p[fx]=p[l[i]]^p[r[i]]^1;
        }
        else{
            if(s[i][0]=='e'&&p[l[i]]==p[r[i]])continue;
            else if(s[i][0]=='o'&&p[l[i]]!=p[r[i]])continue;
            else{
                ans=i-1;
                break;
            }
        }
    }
    if(ans==-1)printf("%d\n",Q);
    else printf("%d\n",ans);
    // fin=clock();
    // printf("time=%lf\n",(double)(fin-beg)/CLOCKS_PER_SEC);
    // rep(i,1,Q)printf("debug:l[%d]=%d r[%d]=%d f[%d]=%d f[%d]=%d p[%d]=%d p[%d]=%d\n",i,l[i],i,r[i],l[i],f[l[i]],r[i],f[r[i]],l[i],p[l[i]],r[i],p[r[i]]);
    return 0;
}