class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty() || nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            if (i==0 || nums[i] > nums[i-1]) {
                int a = nums[i];
                int start = i+1;
                int end = nums.size()-1;
                while (start < end) {
                    int b = nums[start];
                    int c = nums[end];
                    if (a+b+c==0) {
                        res.push_back({a,b,c});
                    } 
                    if (a+b+c > 0) {
                        int currend = end;
                        while (nums[end] == nums[currend] && start < end) {
                            end--;
                        }
                    } else {
                        int currstart = start;
                        while (nums[start] == nums[currstart] && start < end) {
                            start++;
                        }
                    }
                }
            }
        }
        return res;
    }
};
