class Solution {
public:
    vector<int> orig;
    Solution(vector<int> nums) {
        orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    // Knuth Shuffle.
    vector<int> shuffle() {
        vector<int> vec = orig;
        int n = orig.size();
        for (int i=0; i<n-1; i++) {
            int pos = rand() % (n-i);
            swap(vec[i], vec[i+pos]);
            }
        return vec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
