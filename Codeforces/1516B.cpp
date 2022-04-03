#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=2005;

int a[maxn],xsum[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        xsum[0]=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),xsum[i]=xsum[i-1]^a[i];
        bool flag=0;
        for(int i=1;i<n;i++){
            int x=0,last=0,cnt=1;
            for(int j=i+1;j<=n;j++){
                x^=a[j];
                if(x==xsum[i]){
                    x=0;
                    last=j;
                    cnt++;
                }
                else if(x==0){
                    x=0;
                    last=j;
                }
            }
            if(last==n&&cnt!=1){flag=1;break;}
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}