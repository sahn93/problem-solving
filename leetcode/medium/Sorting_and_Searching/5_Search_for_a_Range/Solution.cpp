class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.size() == 0) return res;
        int start = 0, end = nums.size()-1;
        int curr;
        while (start <= end) {
            curr = (start + end) / 2;
            if (nums[curr] < target) {
                start = curr + 1;
            } else if (nums[curr] > target) {
                end = curr - 1;
            } else {
                break;
            }
        }
        if (nums[curr] != target) {
            return res;
        }
        int rstart = curr;
        int lend = curr;
        while (start <= lend) {
            int lcurr = (start + lend) / 2;
            if (nums[lcurr] < target) {
                start = lcurr + 1;
            } else if (nums[lcurr] == target && (lcurr == 0 || nums[lcurr-1] != target)) {
                res[0] = lcurr;
                break;
            } else {
                lend = lcurr - 1;
            }
            // cout << start << lend << '\n';
        }
                       
        while (rstart <= end) {
            int rcurr = (rstart + end) / 2;
            if (nums[rcurr] > target) {
                end = rcurr - 1;
            } else if (nums[rcurr] == target && (rcurr == end || nums[rcurr+1] != target)) {
                res[1] = rcurr;
                break;
            } else {
                rstart = rcurr + 1;
            }
        }       
        return res;
    }
};
