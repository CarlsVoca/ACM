#include<bits/stdc++.h>

using namespace std;

const int maxn=400005;

typedef long long LL;
typedef pair<LL,int> pli;

LL a[maxn],b[maxn];
int pos[maxn];
priority_queue< pli,vector<pli>,greater<pli> > pq;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)pq.push(pli(a[i]+b[1],i)),pos[i]=1;
    int T=n;
    while(T--){
        pli tmp=pq.top();pq.pop();
        printf("%lld\n",tmp.first);
        if(pos[tmp.second]!=n){
            pos[tmp.second]++;
            pq.push(pli(a[tmp.second]+b[pos[tmp.second]],tmp.second));
        }
    }
    return 0;
}