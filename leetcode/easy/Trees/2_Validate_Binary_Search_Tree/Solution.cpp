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
    bool isValidBST(TreeNode* root) {
        if (root==NULL)
            return true;
        // compare maximum of left and root.
        TreeNode* ltree = root->left;
        if (ltree != NULL) {
            while (ltree->right != NULL)
                ltree = ltree->right;
            if (ltree->val >= root->val)
                return false;
        }
        // compare minimum of right and root.
        TreeNode* rtree = root->right;
        if (rtree != NULL) {
            while (rtree->left != NULL)
                rtree = rtree->left;
            if (rtree->val <= root->val)
                return false;
        }
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
