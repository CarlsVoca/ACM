#include<iostream>

using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<((c*60+d)-(a*60+b))/60<<" "<<((c*60+d)-(a*60+b))%60;
    return 0;    
}