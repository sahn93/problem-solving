class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0; 
        // Memoize maximum length from [i][j]. initialize as 0.
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                int len = dfs(i, j, matrix, dp, INT_MAX); 
                res = max(res, len);
            }
        }
        return res;
    }
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int prev) {
        // out of bound or can't go forward.
        if (i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j] >= prev) {
            return 0;
        }
        if (dp[i][j] > 0) {
            return dp[i][j];
        } else {
            int curr = matrix[i][j];
            int tempmax = 0;
            tempmax = max(dfs(i, j+1, matrix, dp, curr), tempmax);
            tempmax = max(dfs(i, j-1, matrix, dp, curr), tempmax);
            tempmax = max(dfs(i+1, j, matrix, dp, curr), tempmax);
            tempmax = max(dfs(i-1, j, matrix, dp, curr), tempmax);
            dp[i][j] = ++tempmax;
            return tempmax;
        }
    }
};
