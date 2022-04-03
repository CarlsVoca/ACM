#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

typedef long long LL;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string s;
        cin>>s;
        int cnt0=0;
        rep(i,0,n-1)if(s[i]=='0')cnt0++;
        if(cnt0==0){puts("DRAW");continue;}//0
        if((n&1)==0)puts("BOB");//2
        else{
            if(cnt0==1)puts("BOB");//1 //中间有
            else{
                if((cnt0&1)==0)puts("BOB");//2 //两边有
                else puts("ALICE");//1 //中间两边都有
            }
        }
    }
    return  0;
}