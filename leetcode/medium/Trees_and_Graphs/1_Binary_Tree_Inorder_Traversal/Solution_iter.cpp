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
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while(curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }
        return ret;
    }
};
