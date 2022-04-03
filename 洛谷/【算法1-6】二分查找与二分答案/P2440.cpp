#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

const int maxn=100005;

int n,k;

int a[maxn];

bool is_right(int x)
{
    int sum=0;
    for(int i=1;i<=n;i++){
      sum+=a[i]/x;
    }
    if(sum>=k)return 1;
    else return 0;
}

int Binary(int l,int r)
{
    int mid=l+r>>1;
    if(mid==0)return 0;
    if(l==r&&is_right(l)){
      return l;
    }
    else if(l==r)return 0;
    if(is_right(mid)){
      return max(mid,Binary(mid+1,r));
    }
    else{
      return Binary(l,mid);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int MAX=0;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      MAX=max(a[i],MAX);
    }
    cout<<Binary(1,MAX)<<endl;
    system("pause");
    return 0;
}




