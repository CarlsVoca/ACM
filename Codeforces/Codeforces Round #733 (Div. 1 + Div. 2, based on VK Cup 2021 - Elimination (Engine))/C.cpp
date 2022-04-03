#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int maxn=100005;
const int INF=0x3f3f3f3f;

int a[maxn],b[maxn];
priority_queue< int > qa1,qb1;
priority_queue< int,vector<int>,greater<int> > qa2,qb2;


bool cmp(int a,int b){return a>b;}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        while(!qa1.empty())qa1.pop();
        while(!qa2.empty())qa2.pop();
        while(!qb1.empty())qb1.pop();
        while(!qb2.empty())qb2.pop();
        int n;
        scanf("%d",&n);
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,n)scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        LL tota=0,totb=0;
        rep(i,1,n-(n-n/4))qa1.push(a[i]);
        per(i,n,n-(n-n/4)+1){
            tota+=a[i];
            qa2.push(a[i]);
        }
        rep(i,1,n-(n-n/4))qb1.push(b[i]);
        per(i,n,n-(n-n/4)+1){
            totb+=b[i];
            qb2.push(b[i]);
        }
        if(tota>=totb){puts("0");continue;}
        rep(i,1,INF){
            if(qa2.size()<(n+i)-(n+i)/4){
                tota+=100;
                qa2.push(100);
            }
            else{
                tota-=qa2.top();
                qa2.pop();
                tota+=100;
                qa2.push(100);
            }
            if(qb2.size()<(n+i)-(n+i)/4){
                if(!qb1.empty()){
                    totb+=qb1.top();
                    qb2.push(qb1.top());
                    qb1.pop();
                }
                else qb2.push(0);
            }
            // printf("debug:%d %d %d\n",i,tota,totb);
            if(tota>=totb){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}