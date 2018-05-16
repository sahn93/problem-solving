class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> target(128, 0);
        for (auto c: t) target[c]++;
        int l = 0, r = 0, len = INT_MAX, start = 0;
        
        int remain = t.size();
        while (r < s.size()) {
            if (target[s[r]] > 0) {
                remain--;
            }
            target[s[r]]--;
            r++;
            
            // valid substring
            while (remain == 0) {
                if (r - l < len) {
                    start = l;
                    len = r - l;
                }
                if (target[s[l]] == 0) {
                    remain++;
                }
                
                target[s[l]]++;
                l++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
