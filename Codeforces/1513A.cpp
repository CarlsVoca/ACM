#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=105;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n)a[i]=i;        
        for(int i=3;i<=n;i+=2){
            if(k){swap(a[i],a[i-1]);k--;}
        }
        if(k)puts("-1");
        else{
            rep(i,1,n)printf("%d ",a[i]);
            putchar('\n');
        }
    }
    return 0;
}