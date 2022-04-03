#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

typedef long long LL;
typedef long double ld;

const int INF=0x3f3f3f3f;
const ld pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317;
const ld eps=1e-6;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c,A,B,C;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&A,&B,&C);
        int cnt1=0,cnt2=0;
        if(a!=-1)cnt1++;if(b!=-1)cnt1++;if(c!=-1)cnt1++;
        if(A!=-1)cnt2++;if(B!=-1)cnt2++;if(C!=-1)cnt2++;
        if(cnt1==3){
            if(a+b>c&&b+c>a&&a+c>b)puts("1");
            else puts("0");
        }
        else if(cnt2==3){
            if(A+B+C==180)puts("syksykCCC");
            else puts("0");
        }
        else if(cnt1==1&&cnt2==2){
            if(A!=-1&&B!=-1){
                if(A+B<180)puts("1");
                else puts("0");
            }
            else if(A!=-1&&C!=-1){
                if(A+C<180)puts("1");
                else puts("0");
            }
            else if(B!=-1&&C!=-1){
                if(B+C<180)puts("1");
                else puts("0");
            }
        }
        else if(cnt1==2&&cnt2==1){
            if(a!=-1&&b!=-1&&C!=-1)puts("1");
            else if(a!=-1&&c!=-1&&B!=-1)puts("1");
            else if(b!=-1&&c!=-1&&A!=-1)puts("1");
            else if(a!=-1&&b!=-1&&A!=-1){
                if(A>=90&&a<=b)puts("0");
                else if(a>=b||(a<b&&fabs(a-b*sin(A/180.0*pi))<eps))puts("1");
                else if(a<b&&a-b*sin(A/180.0*pi)<-eps)puts("0");
                else puts("2");
            }
            else if(a!=-1&&b!=-1&&B!=-1){
                if(B>=90&&b<=a)puts("0");
                else if(b>=a||(b<a&&fabs(b-a*sin(B/180.0*pi))<eps))puts("1");
                else if(b<a&&b-a*sin(B/180.0*pi)<-eps)puts("0");
                else puts("2");
            }
            else if(a!=-1&&c!=-1&&A!=-1){
                if(A>=90&&a<=c)puts("0");
                else if(a>=c||(a<c&&fabs(a-c*sin(A/180.0*pi))<eps))puts("1");
                else if(a<c&&a-c*sin(A/180.0*pi)<-eps)puts("0");
                else puts("2");
            }
            else if(a!=-1&&c!=-1&&C!=-1){
                if(C>=90&&c<=a)puts("0");
                else if(c>=a||(c<a&&fabs(c-a*sin(C/180.0*pi))<eps))puts("1");
                else if(c<a&&c-a*sin(C/180.0*pi)<-eps)puts("0");
                else puts("2");
            }
            else if(b!=-1&&c!=-1&&B!=-1){
                if(B>=90&&b<=c)puts("0");
                else if(b>=c||(b<c&&fabs(b-c*sin(B/180.0*pi))<eps))puts("1");
                else if(b<c&&b-c*sin(B/180.0*pi)<-eps)puts("0");
                else puts("2");
            }
            else if(b!=-1&&c!=-1&&C!=-1){
                if(C>=90&&c<=b)puts("0");
                else if(c>=b||(c<b&&fabs(c-b*sin(C/180.0*pi))<eps))puts("1");
                else if(c<b&&c-b*sin(C/180.0*pi)<-eps)puts("0");
                else puts("2");
            }
        }
    }
    return 0;
}