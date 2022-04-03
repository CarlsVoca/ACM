#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    if(T==1){
        puts("I love Luogu!");
    }
    else if(T==2){
        puts("6 4");
    }
    else if(T==3){
        printf("3\n12\n2\n");
    }
    else if(T==4){
        printf("%.3lf\n",500.0/3);
    }
    else if(T==5){
        printf("%d\n",(260+220)/(12+20));
    }
    else if(T==6){
        cout<<sqrt(36.0+81)<<endl;
    }
    else if(T==7){
        printf("110\n90\n0\n");
    }
    else if(T==8){
        double pi=3.141593,r=5;
        cout<<pi*2*r<<endl<<pi*r*r<<endl<<4/3.0*pi*r*r*r<<endl;
    }
    else if(T==9){
        puts("22");
    }
    else if(T==10){
        puts("9");
    }
    else if(T==11){
        cout<<100/3.0<<endl;
    }
    else if(T==12){
        printf("%d\n%c\n",'M'-'A'+1,'A'+17);
    }
    else if(T==13){
        double pi=3.141593;
        printf("%d\n",(int)pow(4/3.0*pi*4*4*4+4/3.0*pi*10*10*10,1/3.0));
    }
    else if(T==14){
        printf("%d\n",(int)((120-sqrt(120*120-3500*4))/2+0.5));
    }
    return 0;
}