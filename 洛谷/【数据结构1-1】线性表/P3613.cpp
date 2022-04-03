#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF=0x3f3f3f3f;

map<pii,int> a;

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    while(q--){
        int op,i,j,k;
        scanf("%d%d%d",&op,&i,&j);
        if(op==1){
            scanf("%d",&k);
            a[mp(i,j)]=k;
        }
        else{
            printf("%d\n",a[mp(i,j)]);
        }
    }
    return 0;
}