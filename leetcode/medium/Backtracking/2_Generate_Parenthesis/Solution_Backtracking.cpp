class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, 0, res, "");
        return res;
    }
    
    void backtrack(int lnum, int rnum, vector<string>& res, string s) {
        if (lnum == 0 && rnum == 0) {
            res.push_back(s);
            return;
        }
        if (lnum > 0) {
            backtrack(lnum-1, rnum+1, res, s+"(");
        }
        if (rnum > 0)
            backtrack(lnum, rnum-1, res, s+")");
    }
};
