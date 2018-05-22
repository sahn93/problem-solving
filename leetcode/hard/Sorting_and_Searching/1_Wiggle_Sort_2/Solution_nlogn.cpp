class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size();
        int smmax = (n+1)/2, bigmax = n;
        sort(tmp.begin(), tmp.end());
        for (int i=0; i<n; i++) {
            nums[i] = i % 2 == 0 ? tmp[--smmax] : tmp[--bigmax];
        }
    }
};
