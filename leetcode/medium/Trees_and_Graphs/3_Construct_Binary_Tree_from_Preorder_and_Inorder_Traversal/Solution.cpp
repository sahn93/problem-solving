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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int p_start, int p_end, int i_start, int i_end) {
        if (p_start == p_end || i_start == i_end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[p_start]);
        int inorderMid=0; 
        while (inorder[i_start + inorderMid] != preorder[p_start]) {
            inorderMid++;
        }
        root->left = build(preorder, inorder, p_start+1, p_start+inorderMid+1, i_start, i_start+inorderMid);
        root->right = build(preorder, inorder, p_start+inorderMid+1, p_end, i_start+inorderMid+1, i_end);
        return root;
    }
};
