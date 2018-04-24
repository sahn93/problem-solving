class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(nlogn)
        // Using binary search and replace.
        vector<int> lis;
        for (int n: nums) {
            auto lb = lower_bound(lis.begin(), lis.end(), n);
            if (lb == lis.end()) {
                lis.push_back(n);
            } else {
                *lb = n;
            }
        }
        return lis.size();
    }
};
