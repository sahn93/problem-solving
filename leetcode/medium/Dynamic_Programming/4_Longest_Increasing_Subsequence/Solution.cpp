class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(n^2) method.
        // dp[i] means length of LIS which max is nums[i].
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
