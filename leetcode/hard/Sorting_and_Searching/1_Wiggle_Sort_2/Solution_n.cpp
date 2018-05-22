class Solution {
public:
    void threeWayPartition(vector<int>& nums, int val) {
        int i=0, j=0, k = nums.size()-1;
        while (j <= k) {
            if (nums[j] < val) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[j] > val) {
                swap(nums[j], nums[k]);
                k--;
            } else {
                j++;
            }
        }
    }
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        threeWayPartition(nums, nums[mid]);
        
        vector<int> res(n);
        int large = n-1;
        int small = (n%2) ? mid : mid-1;
        for (int i=0; i<n; i+=2) {
            res[i] = nums[small--];
        }
        for (int i=1; i<n; i+=2) {
            res[i] = nums[large--];
        }
        
        nums = res;
    }
};
