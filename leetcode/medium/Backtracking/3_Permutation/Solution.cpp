class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        permute(res, nums, temp, visited);
        return res;
    }
    void permute(vector<vector<int>>& res, vector<int>& nums, vector<int>& temp, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = true;
                permute(res, nums, temp, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};
