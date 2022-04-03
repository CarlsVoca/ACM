#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=35;

char s[maxn];
int len;

void Find(LL pos){
    // printf("debug:%lld\n",pos);
    // printf("debug:pos=%lld\n",pos);
    if(pos>=1&&pos<=len)putchar(s[pos]);
    else{
        LL n=log2((pos-1)/len);
        if(pos==len*(1LL<<n)+1)Find(len*(1LL<<n));
        else Find(pos-len*(1LL<<n)-1);
    }
    return;
}

int main(){
    scanf("%s",s+1);
    len=strlen(s+1);
    LL k;
    scanf("%lld",&k);
    Find(k);
    return 0;
}