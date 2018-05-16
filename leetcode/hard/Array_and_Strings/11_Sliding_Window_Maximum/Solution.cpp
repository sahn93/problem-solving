class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> C; // Maximum candidates, descending order.
        vector<int> maxk;
        
        for (int i=0; i<nums.size(); i++) {
            while (!C.empty() && nums[i] >= nums[C.back()]) {
                C.pop_back();
            }
            while (!C.empty() && C.front() <= i-k) {
                C.pop_front();
            }
            C.push_back(i);
            
            if (i >= k-1) 
                maxk.push_back(nums[C.front()]);
        }
        
        return maxk;
    }
};
