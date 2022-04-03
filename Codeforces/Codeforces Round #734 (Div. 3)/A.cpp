#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int cnt1=n/3,cnt2=n/3;
        if(n%3==1)cnt1++;
        else if(n%3==2)cnt2++;
        printf("%d %d\n",cnt1,cnt2);
    }
    return 0;
}