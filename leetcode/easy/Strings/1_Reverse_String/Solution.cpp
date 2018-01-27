class Solution {
public:
    string reverseString(string s) {
        int left=0, right=s.size()-1;
        char tmp;
        while (left < right) {
            tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
        return s;
    }
};
