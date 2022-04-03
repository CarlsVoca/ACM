class Solution {
public:
    /**
     * @param str: the original string
     * @param sublen: an integer array
     * @return: the new string
     */
    string reformatString(string &str, vector<int> &sublen) {
        int pos=0;
        vector<string> vec;
        for(int i=0;i<sublen.size();i++){
            vec.push_back(str.substr(pos,sublen[i]));
            pos+=sublen[i];
        }
        string res;
        for(int i=0;i+1<vec.size();i+=2)swap(vec[i],vec[i+1]);
        for(int i=0;i+1<=vec.size();i++)res+=vec[i];
        return res;
    }
};