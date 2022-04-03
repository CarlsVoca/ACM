#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;

int a[maxn],b[maxn];
priority_queue< int > pq1;
priority_queue< int,vector<int>,greater<int> > pq2;

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    rep(i,1,m)scanf("%d",&a[i]);
    rep(i,1,n)scanf("%d",&b[i]);
    int k=1;
    rep(i,1,m){
        pq1.push(a[i]);
        pq2.push(pq1.top());
        pq1.pop();
        while(b[k]==i&&k<=n){
            printf("%d\n",pq2.top());
            pq1.push(pq2.top());
            pq2.pop();
            k++;
        }
    }
    return 0;
}