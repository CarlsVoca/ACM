#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int maxn=805;

int n,k;
int arr[maxn*maxn];
int a[maxn][maxn];
vector<pii> v[maxn*maxn];

namespace Discretization{
	int tmp[maxn*maxn],m;
	void do_main(){
		for(int i=1;i<=n*n;i++)tmp[i]=arr[i];
        // puts("???");
        // for(int i=1;i<=n*n;i++)printf("%d ",tmp[i]);
        // puts("???");
		sort(tmp+1,tmp+n*n+1);
		m=unique(tmp+1,tmp+n*n+1)-tmp-1;
		for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){    
                a[i][j]=lower_bound(tmp+1,tmp+m+1,a[i][j])-tmp;
            }
        }
    }
}
using namespace Discretization;

int s[maxn][maxn],sum[maxn][maxn];

bool check(int x){
    memset(s,0,sizeof(s));
    for(int i=1;i<=x;i++){
        for(int j=0;j<v[i].size();j++){
            s[v[i][j].first][v[i][j].second]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+s[i][j];
        }
    }
    for(int i=k;i<=n;i++){
        for(int j=k;j<=n;j++){
            int cnt=sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
            // printf("%d %d:%d\n",i,j,cnt);
            if(cnt>=k*k-(k*k/2+1)+1)return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            arr[(i-1)*n+j]=a[i][j];
        }
    }
    do_main();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // printf("%d %d:%d\n",i,j,a[i][j]);
            v[a[i][j]].push_back(pii(i,j));
        }
    }
    // printf("%d\n",check(4));
    int l=1,r=n*n;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%d\n",tmp[l]);
    return 0;
}