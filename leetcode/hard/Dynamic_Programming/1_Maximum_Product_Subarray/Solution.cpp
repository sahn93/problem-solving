class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int absmax = 0;
        if (n == 0) return -1;
        if (n == 1) return nums[0];
        
        vector<int> dppos(n, 0);
        vector<int> dpneg(n, 0);
        if (nums[0] > 0) {
            dppos[0] = nums[0];
        } else if (nums[0] < 0) {
            dpneg[0] = nums[0];
        }
        
        int res = nums[0];
        
        for (int i=1; i<n; i++) {
            int num = nums[i];
            if (num == 0) {
                dppos[i] = dpneg[i] = 0;
            } else if (num > 0) {
                if (dppos[i-1] == 0) {
                    dppos[i] = num;
                } else {
                    dppos[i] = dppos[i-1] * num;
                }
                dpneg[i] = dpneg[i-1] * num;
            } else {
                dppos[i] = dpneg[i-1] * num;
                if (dppos[i-1] == 0) {
                    dpneg[i] = num;
                } else {
                    dpneg[i] = dppos[i-1] * num;
                }
            }
//            cout << dpneg[i] << " " << dppos[i] << endl;
            res = max(res, dppos[i]); 
        }
        return res;
    }
};
