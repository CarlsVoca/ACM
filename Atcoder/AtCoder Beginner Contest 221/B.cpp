#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length()){
        puts("NO");
    }
    else if(a==b)puts("YES");
    else{
        int n=a.length();
        rep(i,0,n-2){
            swap(a[i],a[i+1]);
            if(a==b){puts("YES");return 0;}
            swap(a[i],a[i+1]);
        }
        puts("NO");
    }
    return 0;
}