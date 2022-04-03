class Solution {
public:
    /**
     * @param trees: the positions of trees.
     * @param d: the minimum beautiful interval.
     * @return: the minimum number of trees to remove to make trees beautiful.
     */
    int treePlanning(vector<int> &trees, int d) {
        // write your code here.
        int n=trees.size();
        int cnt=0,pre=trees[0];
        for(int i=1;i<n;i++){
            if(trees[i]-pre<d)cnt++;
            else pre=trees[i];
        }
        return cnt;
    }
};