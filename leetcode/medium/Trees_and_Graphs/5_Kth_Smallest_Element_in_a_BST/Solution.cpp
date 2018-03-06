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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int count = 1;
        TreeNode* curr = root;
        while (curr->left) {
            stk.push(curr);
            curr = curr->left;
        }
        while (count < k) {
            if (curr->right) {
                curr = curr->right;
                while(curr->left) {
                    stk.push(curr);
                    curr = curr->left;
                }
            } else if (!stk.empty()) {
                curr = stk.top();
                stk.pop();
            }
            count++;
        }
        return curr->val;
    }
};
