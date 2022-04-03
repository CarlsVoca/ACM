class Solution {
public:
    /**
     * @param s: a string.
     * @return: return the values of all the intervals.
     */
    int MOD=20010817;
    long long h1[3005][3005],h2[3005][3005];
    bool check(int L,int R,int len){
        return h1[L][L+len-1]==h2[R][R-len+1];
    }
    int do_main(int L,int R){
        int l=0,r=R-L+1;
        while(l<r){
            int mid=(l+r)/2+1;
            if(check(L,R,mid))l=mid;
            else r=mid-1;
        }
        return l;
    }
    long long suffixQuery(string &s) {
        // write your code here
        int n=s.length();
        s=' '+s;
        memset(h1,0,sizeof(h1));
        memset(h2,0,sizeof(h2));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                h1[i][j]=(h1[i][j-1]*26+s[j]-'a')%MOD;
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=i;j>=1;j--){
                h2[i][j]=(h2[i][j+1]*26+s[j]-'a')%MOD;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans+=do_main(i,j);
            }
        }
        return ans;
    }
};