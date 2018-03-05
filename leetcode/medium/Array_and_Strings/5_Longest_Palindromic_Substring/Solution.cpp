class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int start=0, len=0;
        for(int i=0; i<s.size(); i++) {
            int left = i, right = i;
            while (right < s.size()-1 && s[right+1] == s[right]) {
                right++;
            }
            i = right;
            while (left > 0 && right < s.size()-1 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if (len < right - left + 1) {
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }
};
