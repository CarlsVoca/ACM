#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;

const LL INF=1LL<<60;
const int maxn=1e5+5;

// LL cnt=0;

// namespace Merge_Sort{
// 	int T[maxn];
// 	void do_main(int arr[],int l,int r){
// 		if(l>=r)return;
// 		int mid=l+r>>1;
// 		do_main(arr,l,mid);
// 		do_main(arr,mid+1,r);
// 		int x=l,y=mid+1,z=l;
// 		while(x<=mid||y<=r){
// 			if(y>r||(x<=mid&&arr[x]<=arr[y]))T[z++]=arr[x++];
// 			else T[z++]=arr[y++],cnt+=mid-x+1;
// 		}
// 		for(int i=l;i<=r;i++)arr[i]=T[i];
// 	}
// }
// using namespace Merge_Sort;

int a[maxn];
// int pos[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int cnt1=0,cnt2=0;
        rep(i,1,n){
            scanf("%d",&a[i]);
            if(a[i]&1)cnt1++;
            else cnt2++;
        }
        if(abs(cnt1-cnt2)>1){puts("-1");continue;}
        LL ans=INF,res=0;
        int id1=0,id2=0;
        if(cnt1>=cnt2){
            id1=0,id2=0;
            res=0;
            rep(i,1,n){
                if(a[i]&1){
                    id1++;
                    int pos=id1*2-1;
                    if(pos<i)res+=i-pos;
                }
                else{
                    id2++;
                    int pos=id2*2;
                    if(pos<i)res+=i-pos;
                }
                // printf("debug:%d %lld\n",i,res);
            }
            // printf("1:%lld\n",res);
            ans=min(res,ans);
        }
        if(cnt2>=cnt1){
            res=0;
            id1=id2=0;
            rep(i,1,n){
                if(a[i]&1){
                    id1++;
                    int pos=id1*2;
                    if(pos<i)res+=i-pos;
                }
                else{
                    id2++;
                    int pos=id2*2-1;
                    if(pos<i)res+=i-pos;
                }
            }
            ans=min(ans,res);
        }
        // rep(i,1,n){
        //     if(a[i]&1){
        //         id1++;
        //         pos[i]=id1*2-1;
        //     }
        //     else{
        //         id2++;
        //         pos[i]=id2*2;
        //     }
        // }
        // do_main(pos,1,n);
        // ans=cnt;
        // cnt=0;
        // id1=id2=0;
        // rep(i,1,n){
        //     if(a[i]&1){
        //         id1++;
        //         pos[i]=id1*2;
        //     }
        //     else{
        //         id2++;
        //         pos[i]=id2*2-1;
        //     }
        // }
        // do_main(pos,1,n);
        // ans=min(ans,cnt);
        printf("%lld\n",ans);
    }
    return 0;
}