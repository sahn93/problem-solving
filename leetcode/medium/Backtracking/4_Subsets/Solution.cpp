class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, nums, path, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, int i) {
        if (i==nums.size()) {
            res.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        dfs(res, nums, path, i+1);
        path.pop_back();
        dfs(res, nums, path, i+1);
    }
};
