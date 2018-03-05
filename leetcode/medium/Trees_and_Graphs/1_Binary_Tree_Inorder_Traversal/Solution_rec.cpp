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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        vector<int> left = inorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        
        ret.push_back(root->val);
        
        vector<int> right = inorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        
        return ret;
    }
};
