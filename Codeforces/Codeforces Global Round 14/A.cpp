#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int maxn=105;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x;
        scanf("%d%d",&n,&x);
        rep(i,1,n)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int sum=0;
        rep(i,1,n-1){
            sum+=a[i];
            if(sum==x){
                sum-=a[i];
                swap(a[i],a[i+1]);
                sum+=a[i];
            }
        }
        if(sum+a[n]==x)puts("NO");
        else{
            puts("YES");
            rep(i,1,n)printf("%d ",a[i]);
            putchar('\n');
        }
    }
    return 0;
}