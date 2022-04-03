#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

namespace Fast_IO{
    int read(){
        int x=0;int flag=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;if(ch==EOF)return 0;ch=getchar();}
        while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
        return x*=flag;
    }
}
using namespace Fast_IO;

int a[maxn],f[maxn];
vector<LL> v[maxn];

int main(){
    for(LL i=2;i<=2e5;i++)
        for(LL j=i*i;j<=2e5;j+=i){
            v[j].push_back(i);
        }
    int T;
    scanf("%d",&T);
    while(T--){
        memset(f,0,sizeof(f));
        int n;
        scanf("%d",&n);
        rep(i,1,n)a[i]=read();
        sort(a+1,a+n+1);
        int ans=0;
        rep(i,1,n){
            if(a[i]==1)f[1]++;
            else{
                f[a[i]]=max(f[a[i]]+1,f[1]+1);
                for(int j:v[a[i]]){
                    if(a[i]%j==0){
                        if(f[j])f[a[i]]=max(f[a[i]],f[j]+1);
                        if(f[a[i]/j])f[a[i]]=max(f[a[i]],f[a[i]/j]+1);
                    }
                }
                f[a[i]]=max(f[a[i]],1);
            }
            ans=max(f[a[i]],ans);
            // printf("debug:%d %d\n",a[i],f[a[i]]);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}