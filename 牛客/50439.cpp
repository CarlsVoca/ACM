#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=100005;

struct Data{
    int a,s;
    bool operator < (const Data & d)const{
        return s<d.s;
    }
}d[maxn];

priority_queue< int,vector<int>,greater<int> > s;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&d[i].a,&d[i].s);
    }
    sort(d+1,d+n+1);
    LL ans=0,sum=0;
    int cnt=0;
    for(int i=n;i>=1;i--){
        sum+=d[i].a;s.push(d[i].a);cnt++;
        while(cnt>d[i].s){sum-=s.top();s.pop();cnt--;}
        ans=max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}