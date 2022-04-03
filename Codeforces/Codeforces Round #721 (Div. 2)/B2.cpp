#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

const int maxn=1005;

char s[maxn];

namespace Manacher{
	char tmp[maxn<<1];
	int p[maxn<<1];
	int do_main(char *s){
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)tmp[i*2-1]='%',tmp[i*2]=s[i];
		tmp[len=len*2+1]='%';
		int pos=0,R=0;
		int MAX=0;
		for(int i=1;i<=len;i++){
			if(i<R)p[i]=min(p[pos*2-i],R-i);else p[i]=1;
			while(i-p[i]>=1&&i+p[i]<=len&&tmp[i-p[i]]==tmp[i+p[i]])p[i]++;
			if(i+p[i]>R)pos=i,R=i+p[i];
			MAX=max(MAX,p[i]-1);
		}
		return MAX;
	}
}
using namespace Manacher;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        // printf("%d\n",do_main(s));
        int cnt0=0;
        rep(i,1,n)if(s[i]=='0')cnt0++;
        if(do_main(s)==n){
            // puts("testy");
            if(cnt0==0)puts("DRAW");//0
            else if((n&1)==0)puts("BOB");//2
            else{
                if(cnt0==1)puts("BOB");//1 //中间有
                else{
                    if((cnt0&1)==0)puts("BOB");//2 //两边有
                    else puts("ALICE");//1 //中间两边都有
                }
            }
            continue;
        }
        if((cnt0==2)&&(n&1)&&s[n/2+1]=='0')puts("DRAW");
        else puts("ALICE");
        // int l=1,r=n,cnt=0;
        // while(l<r){
        //     if(s[l]=='0'&&s[r]=='0'){
        //         l++;r--;
        //         continue;
        //     }
        //     if(s[l]=='0'||s[r]=='0'){
        //         cnt++;
        //         s[l]='1';
        //         s[r]='1';
        //     }
        //     l++;r--;
        // }
        // int del=0;
        // if(cnt&1){
        //     del=cnt;
        //     int cnt0=0;
        //     rep(i,1,n)if(s[i]=='0')cnt0++;
        //     if(cnt0==0);//0
        //     else if((n&1)==0)del+=2;//2
        //     else{
        //         if(cnt0==1)del++;//1 //中间有
        //         else{
        //             if((cnt0&1)==0)del+=2;//2 //两边有
        //             else del--;//1 //中间两边都有
        //         }
        //     }
        // }
        // else{
        //     del=cnt;
        //     int cnt0=0;
        //     rep(i,0,n-1)if(s[i]=='0')cnt0++;
        //     if(cnt0==0);//0
        //     else if((n&1)==0)del-=2;//2
        //     else{
        //         if(cnt0==1)del-=2;//1 //中间有
        //         else{
        //             if((cnt0&1)==0)del-=2;//2 //两边有
        //             else del++;//1 //中间两边都有
        //         }
        //     }
        // }
        // if(del==0)puts("DRAW");
        // else if(del>0)puts("ALICE");
        // else puts("BOB");
    }
    return  0;
}