#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==b){
        printf("%d\n",c);
    }
    else if(b==c){
        printf("%d\n",a);
    }
    else if(a==c){
        printf("%d\n",b);
    }
    else puts("0");
    return 0;
}