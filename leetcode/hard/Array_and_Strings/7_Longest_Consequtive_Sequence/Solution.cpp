class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest = 0;
        
        for (int n: nums) {
            s.insert(n);
        }
        for (int n: nums) {
            if (s.count(n-1) > 0) continue;
            
            int len = 1;
            while (s.count(n+len) > 0) {
                len++;
            }
            if (len > longest) longest = len;
        }
        
        return longest;
    }
};
