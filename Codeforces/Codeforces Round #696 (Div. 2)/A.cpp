#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        string b;
        cin>>n>>b;
        a[0]=1;
        int pre;
        if(b[0]=='0')pre=1;
        else pre=2;
        rep(i,1,n-1){
            if(b[i]=='0'){
                if(pre==1)a[i]=0,pre=0;
                else if(pre==2)a[i]=1,pre=1;
                else if(pre==0)a[i]=1,pre=1;
            }
            else{
                if(pre==1)a[i]=1,pre=2;
                else if(pre==2)a[i]=0,pre=1;
                else if(pre==0)a[i]=1,pre=2;    
            }
        }
        // printf("ans");
        rep(i,0,n-1)printf("%d",a[i]);
        putchar('\n');
    }
    return 0;
}