class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's Cycle Detection
        int tortoise = 0, hare = 0, lam = 0;
        while (true) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (tortoise == hare) break;
        }
        while (true) {
            tortoise = nums[tortoise];
            lam = nums[lam];
            if (tortoise == lam) break;
        }
        return lam;
    }
};
