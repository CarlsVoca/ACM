#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int a[maxn],b[maxn],c[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        int num=0;
        b[++num]=1;
        int sz=1;
        rep(i,3,n){
            if(a[i]>a[i-1])sz++;
            else{
                b[++num]=sz;
                sz=1;
            }
        }
        b[++num]=sz;
        int dep,pos=2;
        for(dep=0;;dep++){
            if(dep==0){c[dep]=1;continue;}
            int cnt=0;
            c[dep]=0;
            while(pos<=num&&cnt<c[dep-1])c[dep]+=b[pos],pos++,cnt++;
            if(pos>num)break;
        }
        printf("%d\n",dep);
    }
    return 0;
}