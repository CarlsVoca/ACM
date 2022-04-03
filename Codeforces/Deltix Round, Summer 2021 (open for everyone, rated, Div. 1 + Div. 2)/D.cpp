#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const int INF=0x3f3f3f3f;
const int maxn=1e4+5;

int a[maxn];

int main(){
    int n,k;
    cin>>n>>k;
    int i;
    for(i=1;i+2<=n;i+=3){
        LL res1=0,res2=0,res3=0,x;
        cout<<"or "<<i<<" "<<i+1<<endl;
        fflush(stdout);
        cin>>x;
        res1+=x;
        cout<<"and "<<i<<" "<<i+1<<endl;
        fflush(stdout);
        cin>>x;
        res1+=x;
        cout<<"or "<<i<<" "<<i+2<<endl;
        fflush(stdout);
        cin>>x;
        res2+=x;
        cout<<"and "<<i<<" "<<i+2<<endl;
        fflush(stdout);
        cin>>x;
        res2+=x;
        cout<<"or "<<i+1<<" "<<i+2<<endl;
        fflush(stdout);
        cin>>x;
        res3+=x;
        cout<<"and "<<i+1<<" "<<i+2<<endl;
        fflush(stdout);
        cin>>x;
        res3+=x;
        a[i]=(res1+res2-res3)/2;
        a[i+1]=(res1+res3-res2)/2;
        a[i+2]=(res2+res3-res1)/2;
    }
    for(;i<=n;i++){
        LL res=0,x;
        cout<<"or "<<1<<" "<<i<<endl;
        fflush(stdout);
        cin>>x;
        res+=x;
        cout<<"and "<<1<<" "<<i<<endl;
        fflush(stdout);
        cin>>x;
        res+=x;
        a[i]=res-a[1];
    }
    sort(a+1,a+n+1);
    cout<<"finish "<<a[k]<<endl;
    fflush(stdout);
    return 0;
}