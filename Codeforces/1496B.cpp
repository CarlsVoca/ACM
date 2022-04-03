#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n)scanf("%d",&a[i]);
        if(k==0){printf("%d\n",n);continue;}
        sort(a+1,a+n+1);
        int Mex=-1;
        rep(i,1,n){
            if(a[i]!=i-1){
                Mex=i-1;
                break;
            }
        }
        if(Mex==-1)Mex=n;
        if(Mex==n){
            printf("%d\n",n+k);
            continue;
        }
        else{
            int nw=ceil((Mex+a[n])/2.0);
            int pos=lower_bound(a+1,a+n+1,nw)-a;
            if(a[pos]==nw)printf("%d\n",n);
            else printf("%d\n",n+1);
        }
    }
    return 0;
}