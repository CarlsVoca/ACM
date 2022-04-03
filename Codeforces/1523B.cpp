#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int a[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        printf("%d\n",n*3);
        for(int i=1;i<=n;i+=2){
            printf("1 %d %d\n",i,i+1);
            printf("2 %d %d\n",i,i+1);
            printf("1 %d %d\n",i,i+1);
            printf("1 %d %d\n",i,i+1);
            printf("2 %d %d\n",i,i+1);
            printf("1 %d %d\n",i,i+1);
        }
    }
    return 0;
}