class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const int l, const int r){return l>r;});
        return nums[k-1];
    }
};
