#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)swap(a,b);if(b>c)swap(b,c);if(a>b)swap(a,b);if(b>c)swap(b,c);
    if(a+b<=c)puts("Not triangle");
    else{    
        if(a*a+b*b==c*c)puts("Right triangle");
        if(a*a+b*b>c*c)puts("Acute triangle");
        if(a*a+b*b<c*c)puts("Obtuse triangle");
        if(a==b||b==c)puts("Isosceles triangle");
        if(a==c)puts("Equilateral triangle");
    }
    return 0;
}