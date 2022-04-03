#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=100005;

int a[maxn],cnt[maxn];

namespace Discretization{
	int tmp[maxn];
	void do_main(int arr[],int size){
		memcpy(tmp+1,arr+1,size<<2);
		sort(tmp+1,tmp+size+1);
		int m=unique(tmp+1,tmp+size+1)-tmp-1;
		for(int i=1;i<=size;i++)arr[i]=lower_bound(tmp+1,tmp+m+1,arr[i])-tmp;
	}
}
using namespace Discretization;

int R[maxn];
LL sum[maxn];

int main(){
    memset(cnt,0,sizeof(cnt));
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    do_main(a,n);
    int ct=0;
    int pos=1;
    cnt[a[1]]++;ct++;
    while(ct<k&&pos<=n){
        pos++;
        cnt[a[pos]]++;
        if(cnt[a[pos]]==1)ct++;
    }
    R[1]=pos;
    for(int i=2;i<=n;i++){
        cnt[a[i-1]]--;
        if(cnt[a[i-1]]==0)ct--;
        R[i]=R[i-1];
        while(ct<k&&R[i]<=n){
            R[i]++;
            cnt[a[R[i]]]++;
            if(cnt[a[R[i]]]==1)ct++;
        }
    }
    sum[0]=0;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+R[i];
    LL ans=0;
    while(m--){
        int l1,r1;
        scanf("%d%d",&l1,&r1);
        int l=min(l1^ans,r1^ans)+1,r=max(l1^ans,r1^ans)+1;
        int ll=l,rr=r;
        while(ll<rr){
            int mid=(ll+rr>>1)+1;
            if(R[mid]<=r)ll=mid;
            else rr=mid-1;
        }
        if(R[ll]>r)ans=0;
        else ans=1LL*r*(ll-l+1)+(ll-l+1)-(sum[ll]-sum[l-1]);
        printf("%lld\n",ans);
    }
    return 0;
}