#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

namespace Fast_IO{
    int read(){
        int x=0;int flag=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;if(ch==EOF)return 0;ch=getchar();}
        while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
        return x*flag;
    }
}
using namespace Fast_IO;

unordered_map<int,bool> mp;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        mp.clear();
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            int x;
            x=read();
            if(mp[x])continue;
            else{
                printf("%d ",x);
                mp[x]=1;
            }
        }
        putchar('\n');
    }
    return 0;
}