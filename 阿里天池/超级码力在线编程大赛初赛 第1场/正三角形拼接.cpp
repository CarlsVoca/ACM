class Solution {
public:
    /**
     * @param lengths: the lengths of sticks at the beginning.
     * @return: return the minimum number of cuts.
     */
    int makeEquilateralTriangle(vector<int> &lengths) {
        // write your code here.
        int n=lengths.size();
        map<int,int> cnt;
        int ans=2;
        sort(lengths.begin(),lengths.end());
        for(int i=0;i<n;i++){
            if(!cnt.count(lengths[i]))cnt[lengths[i]]=0;
            cnt[lengths[i]]++;
            if(cnt[lengths[i]]==3)ans=min(ans,0);
            if(lengths[i]%2==0&&cnt.count(lengths[i]/2))ans=min(ans,1);
            if(cnt.count(lengths[i]*2))ans=min(ans,1);
            if(cnt[lengths[i]]==2&&i!=n-1)ans=min(ans,1);
        }
        return ans;
    }
};