#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
double x,y=0;
cin>>x;
if(x>150)
  {y+=150*0.4463;
  if(x>400)
    y+=250*0.4663+(x-400)*0.5663;
  else
    y+=(x-150)*0.4663;}
else
  y+=x*0.4463;
printf("%.1f",y);

return 0;
    
    }