class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (int i=0; i<s.size(); i++) {
            sum *= 26;
            int num = s[i] - 'A' + 1;
            sum += num;
        }
        return sum;
    }
};
