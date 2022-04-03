#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

void print(int x){
    if(x==0){printf("0");return;}
    int n=log2(x);
    bool flag=0;
    per(i,n,0){
        if((1<<i)&x){
            if(!flag){
                if(i==1)printf("2");
                else{
                    printf("2(");
                    print(i);
                    printf(")");
                }
                flag=1;
            }
            else{
                if(i==1)printf("+2");
                else{
                    printf("+2(");
                    print(i);
                    printf(")");
                }
            }
        }
    }
}

int main(){
    int x;
    scanf("%d",&x);
    print(x);
    return 0;
}