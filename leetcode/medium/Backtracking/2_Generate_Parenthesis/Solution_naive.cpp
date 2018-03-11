class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n<1) {
            ret.push_back("");
            return ret;
        }
        if (n==1) {
            ret.push_back("()");
            return ret;
        }
        for (int i=0; i<n; i++) {
            for (string &s: generateParenthesis(n-1-i)) {
                for (string &ss: generateParenthesis(i)) {
                    ret.push_back("("+s+")"+ss);
                }
            }
        }
        return ret;
    }
};
