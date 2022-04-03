#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e6+5;

int n,k;
int a[maxn];

namespace Union_Find{
    int fl[maxn],fr[maxn],l[maxn],r[maxn];
    void Pre(){
        for(int i=1;i<=2*n*(1<<k);i++)fl[i]=fr[i]=l[i]=r[i]=i;
    }
    int Findl(int x){
        return fl[x]==x?x:fl[x]=Findl(fl[x]);
    }
    int Findr(int x){
        return fr[x]==x?x:fr[x]=Findr(fr[x]);
    }
    void Union(int x,int y){
        int fx=Findr(x),fy=Findl(y);
        fr[fx]=r[fx]=fy;fl[fy]=l[fy]=fx;
    }
}
using namespace Union_Find;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        per(i,2*n*(1<<k),1)scanf("%d",&a[i]);
        Pre();
        per(i,2*n*(1<<k),1){
            if((i+1)/2<=n)break;
            int nowk=log2(((i+1)/2-1)/n)+1;
            int x=(i+1)/2;
            int y=n*(1<<nowk)-x+1;
            if(i%2==0){
                if((x+n-1)/n%2==0)Union(i,y*2-1);
                else Union(y*2-1,i);
            }
            else{
                if((x+n-1)/n%2==0)Union(i,y*2);
                else Union(y*2,i);
            }
            // printf("l[%d]=%d r[%d]=%d\n",2*n*(1<<k)-i+1,2*n*(1<<k)-l[i]+1,2*n*(1<<k)-i+1,2*n*(1<<k)-r[i]+1);
        }
        int cnt=0;
        per(i,n*2,1){
            int tmp=Findl(i);
            printf("%d",a[tmp]);if((++cnt)!=2*n*(1<<k))putchar(' ');
            while(r[tmp]!=tmp){
                tmp=r[tmp];
                printf("%d",a[tmp]);if((++cnt)!=2*n*(1<<k))putchar(' ');
            }
        }
        puts("");
    }
    return 0;
}