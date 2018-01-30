class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
            return "";

        string prefix = strs[0];
        int idx;
        for (int i=1; i<strs.size(); i++) {
            idx=0;
            while (idx<prefix.size() && idx<strs[i].size() && prefix[idx]==strs[i][idx])
                idx++;
            prefix.erase(prefix.begin()+idx, prefix.end());
        }
        return prefix;
    }
};
