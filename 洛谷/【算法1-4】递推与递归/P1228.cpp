#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

void print(int bx,int by,int x,int y,int k){
    int ex=bx+(1<<k)-1,ey=by+(1<<k)-1;
    int t;
    if(x<=(bx+ex)/2&&y<=(by+ey)/2)t=1;
    if(x<=(bx+ex)/2&&y>(by+ey)/2)t=2;
    if(x>(bx+ex)/2&&y<=(by+ey)/2)t=3;
    if(x>(bx+ex)/2&&y>(by+ey)/2)t=4;
    if(k==1){
        if(t==1)printf("%d %d %d\n",ex,ey,1);
        if(t==2)printf("%d %d %d\n",ex,by,2);
        if(t==3)printf("%d %d %d\n",bx,ey,3);
        if(t==4)printf("%d %d %d\n",bx,by,4);
    }
    else{
        if(t==1){
            printf("%d %d %d\n",(bx+ex)/2+1,(by+ey)/2+1,1);
            print(bx,by,x,y,k-1);
            print(bx,(by+ey)/2+1,(bx+ex)/2,(by+ey)/2+1,k-1);
            print((bx+ex)/2+1,by,(bx+ex)/2+1,(by+ey)/2,k-1);
            print((bx+ex)/2+1,(by+ey)/2+1,(bx+ex)/2+1,(by+ey)/2+1,k-1);
        }
        if(t==2){
            printf("%d %d %d\n",(bx+ex)/2+1,(by+ey)/2,2);
            print(bx,by,(bx+ex)/2,(by+ey)/2,k-1);
            print(bx,(by+ey)/2+1,x,y,k-1);
            print((bx+ex)/2+1,by,(bx+ex)/2+1,(by+ey)/2,k-1);
            print((bx+ex)/2+1,(by+ey)/2+1,(bx+ex)/2+1,(by+ey)/2+1,k-1);
        }
        if(t==3){
            printf("%d %d %d\n",(bx+ex)/2,(by+ey)/2+1,3);
            print(bx,by,(bx+ex)/2,(by+ey)/2,k-1);
            print(bx,(by+ey)/2+1,(bx+ex)/2,(by+ey)/2+1,k-1);
            print((bx+ex)/2+1,by,x,y,k-1);
            print((bx+ex)/2+1,(by+ey)/2+1,(bx+ex)/2+1,(by+ey)/2+1,k-1);
        }
        if(t==4){
            printf("%d %d %d\n",(bx+ex)/2,(by+ey)/2,4);
            print(bx,by,(bx+ex)/2,(by+ey)/2,k-1);
            print(bx,(by+ey)/2+1,(bx+ex)/2,(by+ey)/2+1,k-1);
            print((bx+ex)/2+1,by,(bx+ex)/2+1,(by+ey)/2,k-1);
            print((bx+ex)/2+1,(by+ey)/2+1,x,y,k-1);
        }
    }
}

int main(){
    int k,x,y;
    scanf("%d%d%d",&k,&x,&y);
    print(1,1,x,y,k);
    return 0;
}