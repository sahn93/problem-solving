class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return false;
        sort(nums.begin(), nums.end());
        int temp = nums.front();
        for (int i=1; i<nums.size(); i++) {
            if (temp == nums[i])
                return true;
            temp = nums[i];
        }
        return false;
    }
};
