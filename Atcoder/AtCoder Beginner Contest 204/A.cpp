#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int a[maxn],b[maxn],x[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    int num,cnt,id=0;
    for(int i=1;i<=n;i++){
        if(i==1||x[i]!=x[i-1]||x[i]!=1){
            a[++id]=x[i];
            b[id]=1;
        }
        else b[id]++;
    }
    int ans=0;
    for(int i=1;i<=id;i++){
        if(a[i]==1){
            ans+=b[i]*(b[i]-1)/2;//[1,2] [4,5] [4,6] [5,6]
        }
        else{
            if(a[i-1]==1)ans+=b[i-1];//[1,3] [2,3] [4,7] [5,7] [6,7]
            if(a[i+1]==1)ans+=b[i+1];//[3,4] [3,5] [3,6] 
            if(a[i-1]==1&&a[i+1]==1)ans+=b[i-1]*b[i+1];//[1,4] [1,5] [1,5] [2,4] [2,5] [2,6]
        }
    }
    printf("%d\n",ans);
    return 0;
}