class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> upper(nums.size(), 1);
        int mult = 1;
        for (int i = nums.size()-1; i>=0; i--) {
            upper[i] = mult;
            mult *= nums[i];
        }
        int lower = 1;
        for (int i=0; i<nums.size(); i++) {
            res[i] = lower * upper[i];
            lower *= nums[i];
        }
        return res;
    }
};
