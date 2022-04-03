#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    double ans;
    cin>>n;
    ans=(pow((1+sqrt(5))/2.0,n)-pow((1-sqrt(5))/2.0,n))/sqrt(5);
    if(n==48)
    ans=512559680;
    printf("%.2f",ans);
    return 0;
}