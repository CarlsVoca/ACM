#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

int main()
{
	int p1,p2,p3;
	scanf("%d%d%d",&p1,&p2,&p3);
	string a;
	cin>>a;
	printf("%c",a[0]);
	for(int i=1;i<a.length()-1;i++){
		if(a[i]!='-'||a[i+1]<=a[i-1]||!((isalpha(a[i-1])&&isalpha(a[i+1]))||(isdigit(a[i-1])&&isdigit(a[i+1]))))
			printf("%c",a[i]);
		else if(a[i]=='-'){
			if((isalpha(a[i-1])&&isalpha(a[i+1]))||(isdigit(a[i-1])&&isdigit(a[i+1]))){
				if(a[i+1]>a[i-1]+1){
					if(p1==1){
						if(p3==1){
							for(char ch=a[i-1]+1;ch<=a[i+1]-1;ch++)
								for(int j=1;j<=p2;j++)
									printf("%c",ch);
						}
						else{
							for(char ch=a[i+1]-1;ch>=a[i-1]+1;ch--)
								for(int j=1;j<=p2;j++)
									printf("%c",ch);	
						}
					}
					else if(p1==2){
						if(p3==1){
							for(char ch=a[i-1]+1;ch<=a[i+1]-1;ch++)
								for(int j=1;j<=p2;j++)
									printf("%c",toupper(ch));
						}
						else{
							for(char ch=a[i+1]-1;ch>=a[i-1]+1;ch--)
								for(int j=1;j<=p2;j++)
									printf("%c",toupper(ch));	
						}
					}
					else{
						for(char ch=a[i-1]+1;ch<=a[i+1]-1;ch++)
								for(int j=1;j<=p2;j++)
									printf("*");
					}
				}
			}
		}
	}
	printf("%c\n",a[a.length()-1]);
	return 0;
}

