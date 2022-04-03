#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=2e5+5;

char s[2*maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        rep(i,n,n*2-1)s[i]=s[i-n];
        int pos1=0;
        rep(i,1,n-1)if(s[i]!=s[0]){pos1=i;break;}
        int pos=pos1,ans=0,len=1;
        while(pos<=pos1+n-1){
            // printf("Debug:%d\n",pos);
            len=1;
            while(s[pos+1]==s[pos]&&pos+1<=pos1+n-1)pos++,len++;
            ans+=len/3;
            // printf("len:%d\n",len);
            pos++;
        }
        if(pos1==0){
            if(n==1||n==2)puts("0");
            else printf("%d\n",(n+2)/3);
        }
        else printf("%d\n",ans);
    }
    return 0;
}