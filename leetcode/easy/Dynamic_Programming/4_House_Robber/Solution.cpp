class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        int ppmax = 0;
        int pmax = nums[0];
        bool stole = true;
        for (int i=1; i<nums.size(); i++) {
            if (ppmax + nums[i] < pmax) {
                ppmax = pmax;
            } else {
                int temp = pmax;
                pmax = ppmax + nums[i];
                ppmax = temp;
            }
        }
        return pmax;
    }
};
