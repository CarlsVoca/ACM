#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=100005;

int a[maxn];

priority_queue< int > pq1;
priority_queue< int,vector<int>,greater<int> > pq2;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n){
        pq1.push(a[i]);
        pq2.push(pq1.top());
        pq1.pop();
        if(i&1){
            printf("%d\n",pq2.top());
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    return 0;
}