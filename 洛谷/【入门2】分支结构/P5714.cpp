#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    double m,h;
    scanf("%lf%lf",&m,&h);
    double BMI=m/h/h;
    if(BMI<18.5)puts("Underweight");
    else if(BMI>=24){
        cout<<BMI<<endl;
        puts("Overweight");
    }
    else puts("Normal");
    return 0;
}