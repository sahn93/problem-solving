class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = 0;
        for (int i=0; i<nums.size()-two;){
            if (nums[i] == 0 && i > zero) {
                swap(nums[i], nums[zero]);
                zero++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[nums.size()-1-two]);
                two++;
            } else {
                i++;
            }
        }
        
    }
};
