class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        int p=0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                p++;
                nums[p] = nums[i];
            }
        }
        return p+1;
    }
};
