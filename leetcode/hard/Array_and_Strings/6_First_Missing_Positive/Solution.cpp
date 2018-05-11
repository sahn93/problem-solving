class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int np = nums.size();
        for (int i=0; i<np; i++) {
            if (nums[i] <= 0) {
                int tmp = nums[i];
                nums[i] = nums[np-1];
                nums[np-1] = tmp;
                np--;
                i--;
            }
        }
        for (int i=0; i<np; i++) {
            if (nums[i] <= np) {
                if (nums[abs(nums[i])-1] > 0) {
                    nums[abs(nums[i])-1] *= -1;
                }
            }
        }
        for (int i=0; i<np; i++) {
            if (nums[i] > 0) return i+1;
        }
        return np + 1;
    }
};
