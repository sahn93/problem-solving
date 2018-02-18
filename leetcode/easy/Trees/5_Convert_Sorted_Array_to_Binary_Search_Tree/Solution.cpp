/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = nums.size();
        return helper(nums, 0, s);
    }
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start >= end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode* rt = new TreeNode(nums[mid]);
        rt->left = helper(nums, start, mid);
        rt->right = helper(nums, mid+1, end);
        return rt;
    }
};
