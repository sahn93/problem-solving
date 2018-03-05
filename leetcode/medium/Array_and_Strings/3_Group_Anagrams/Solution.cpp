class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> amap;
        for(string& s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            amap[key].push_back(s);
        }
        for (auto it = amap.begin(); it != amap.end(); ++it) {
            ret.push_back(it->second);    
        }
        return ret;
    }
};
