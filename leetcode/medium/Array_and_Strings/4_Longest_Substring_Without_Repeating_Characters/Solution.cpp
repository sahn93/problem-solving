class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int start=0, end=0;
        int length=1;
        for (int i=1; i<s.size(); ++i) {
            int j = start;
            while(s[j] != s[i] && j < i) {
                j++;
            }
            if (i != j)
                start = j+1;
            end++;
            if (length < end-start+1) {
                length = end-start+1;
            }
        }
    
        return length; 
    }
};
