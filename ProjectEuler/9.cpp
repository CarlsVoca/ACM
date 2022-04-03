#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("answer.txt","w",stdout);
	for(int a=1;a<1000;a++)
		for(int b=1;b+a<1000;b++){
			int c=1000-a-b;
			if(a*a+b*b==c*c){
				printf("%d\n",a*b*c);
				return 0;
			}
		}
	return 0;
}
