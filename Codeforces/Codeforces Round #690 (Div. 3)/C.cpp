#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int x;
        scanf("%d",&x);
        vector<int> vec;
        per(i,9,1){
            if(x>=i){
                x-=i;
                vec.push_back(i);
            }
        }
        if(x)printf("-1");
        else per(i,(int)vec.size()-1,0)printf("%d",vec[i]);
        putchar('\n');
    }
    return 0;
}