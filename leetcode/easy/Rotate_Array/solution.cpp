class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (nums.size() == 0 || k == 0)
            return;
        int temp[k];
        // copy last k elements
        for (int i=0; i<k; i++) {
            temp[i] = nums[nums.size()-k+i];
        }
        // shift first nums.size() - k elements
        for (int i=0; i<nums.size()-k; i++) {
            nums[nums.size()-1-i] = nums[nums.size()-1-k-i];
        }
        // fill first k elements
        for (int i=0; i<k; i++) {
            nums[i] = temp[i];
        }
    }
};
