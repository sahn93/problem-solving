class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        return ret;
    }
    
    void dfs(int start, const string &s, vector<string> &path, vector<vector<string>> &ret) {
        if (start == s.size()) {
            ret.push_back(path);
            return;
        }
        
        for (int i=start; i<s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i-start+1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
