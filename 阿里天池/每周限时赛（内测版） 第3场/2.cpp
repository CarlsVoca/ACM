class Solution {
public:
    /**
     * @param cost: the cost
     * @param val: the value
     * @return: the all cost
     */
    typedef long long LL;
    LL sum[100005];
    int n,m;
    long long doingHomework(vector<int> &cost, vector<int> &val) {
        m=cost.size();n=val.size();
        sum[0]=0;
        for(int i=1;i<=m;i++)sum[i]=sum[i-1]+cost[i-1];
        sum[m+1]=(1LL<<60);
        LL res=0;
        for(int i=0;i<n;i++){
            res+=sum[upper_bound(sum,sum+m+2,val[i])-sum-1];
        }
        return res;
    }
};