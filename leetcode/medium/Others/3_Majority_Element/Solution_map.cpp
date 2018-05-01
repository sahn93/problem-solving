class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int threshold = nums.size()/2;
        for (int n: nums) {
            if (m.count(n) == 0) {
                m[n] = 1;
            } else {
                m[n]++;
            }
            if (m[n] > threshold) {
                return n;
            }
        }
        return 0;
    }
};
