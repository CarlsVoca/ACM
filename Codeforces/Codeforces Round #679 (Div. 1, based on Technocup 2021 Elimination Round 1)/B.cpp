#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=200005;
    
struct Data{
    char tp;
    int x,id;
}d[maxn];

stack<Data> sta;

int num[maxn];
priority_queue< int,vector<int>,greater<int> > pq;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,2*n){
        cin>>d[i].tp;
        if(d[i].tp=='-')scanf("%d",&d[i].x);
        d[i].id=i;
    }
    rep(i,1,2*n){
        if(d[i].tp=='+')sta.push(d[i]);
        else{
            if(sta.empty()){puts("NO");return 0;}
            else{
                num[sta.top().id]=d[i].x;
                sta.pop();
            }
        }
    }
    // printf("debug:%d\n",sta.top().id);
    if(!sta.empty()){puts("NO");return 0;}
    // puts("Carls");
    rep(i,1,2*n){
        if(num[i])pq.push(num[i]);
        else{
            if(pq.top()!=d[i].x){puts("NO");return 0;}
            else pq.pop();
        }
    }
    puts("YES");
    rep(i,1,2*n){
        if(num[i])printf("%d ",num[i]);
    }
    return 0;
}