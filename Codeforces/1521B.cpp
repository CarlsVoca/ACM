#include<bits/stdc++.h>

using namespace std;

const int INF=0x7fffffff;
const int maxn=100005;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int a[maxn];

struct Data{
    int a,b,c,d;
};
vector<Data> v;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        v.clear();
        int n;
        scanf("%d",&n);
        int MIN=INF,minpos=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]<MIN){
                MIN=a[i];
                minpos=i;
            }
        }
        for(int i=1;i<minpos;i++){
            if(gcd(a[i],a[i+1])!=1){
                while(gcd(a[i],a[i+1])!=1||(i!=1&&gcd(a[i],a[i-1])!=1))a[i]++;
                v.push_back(Data{minpos,i,MIN,a[i]});
            }
        }
        for(int i=minpos+1;i<=n;i++){
            if(gcd(a[i],a[i-1])!=1){
                while(gcd(a[i],a[i-1])!=1||(i!=n&&gcd(a[i],a[i+1])!=1))a[i]++;
                v.push_back(Data{minpos,i,MIN,a[i]});
            }
        }
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++){
            printf("%d %d %d %d\n",v[i].a,v[i].b,v[i].c,v[i].d);
        }
    }
    return 0;
}