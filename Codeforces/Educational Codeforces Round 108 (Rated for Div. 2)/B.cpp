#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if(n-1+n*(m-1)==k||m-1+m*(n-1)==k)puts("YES");
        else puts("NO");
    }
}