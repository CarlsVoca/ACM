#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int h,m;

int f(int x){
    switch (x)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    case 2:
        return 5;
        break;
    case 3:
        return -1;
        break;
    case 4:
        return -1;
        break;
    case 5:
        return 2;
        break;
    case 6:
        return -1;
        break;
    case 7:
        return -1;
        break;
    case 8:
        return 8;
        break;
    case 9:
        return -1;
        break;
    default:
        break;
    }
    return -1;
}

int rev(int x){
    int a=x/10,b=x%10;
    if(f(b)==-1||f(a)==-1)return -1;
    return f(b)*10+f(a);
}

bool judge(int a,int b){
    int aa=rev(b),bb=rev(a);
    if(aa==-1||bb==-1)return 0;
    if(aa>=h||bb>=m)return 0;
    return 1;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string t;
        cin>>h>>m>>t;
        int a=(t[0]-'0')*10+(t[1]-'0'),b=(t[3]-'0')*10+(t[4]-'0');
        while(!judge(a,b)){
            b++;
            if(b==m){
                b=0;
                a++;
                if(a==h)a=0;
            }
        }
        printf("%02d:%02d\n",a,b);
    }
    return 0;
}