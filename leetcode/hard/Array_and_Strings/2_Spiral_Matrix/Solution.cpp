class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int left = 0, right = matrix[0].size()-1;
        int top = 0, bot = matrix.size()-1;
        while (left <= right && top <= bot) {
            for (int i=left; i<=right; i++) {
                res.push_back(matrix[top][i]);
            }
            for (int j=top+1; j<=bot; j++) {
                res.push_back(matrix[j][right]);
            }
            if (bot == top) break;
            for (int i=right-1; i>=left; i--) {
                res.push_back(matrix[bot][i]);
            }
            if (left == right) break;
            for (int j=bot-1; j>top; j--) {
                res.push_back(matrix[j][left]);
            }
            left++;
            right--;
            top++;
            bot--;
            // cout << left <<right << top << bot << endl;
            // return res;
        }
        return res;
    }
};
