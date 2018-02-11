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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        if (!(root->left) && !(root->right))
            return true;
        if (!(root->left && root->right))
            return false;
            
        stack<TreeNode*> lstack;
        stack<TreeNode*> rstack;
        lstack.push(root->left);
        rstack.push(root->right);
        TreeNode* lcurr;
        TreeNode* rcurr;
        
        while (!lstack.empty()) {
            if (rstack.empty())
                return false;
            lcurr = lstack.top();
            lstack.pop();
            rcurr = rstack.top();
            rstack.pop();
            if (lcurr==NULL && rcurr==NULL)
                continue;
            else if (!(lcurr && rcurr))
                return false;
            if (lcurr->val != rcurr->val)
                return false;
            
            lstack.push(lcurr->left);
            lstack.push(lcurr->right);

            rstack.push(rcurr->right);
            rstack.push(rcurr->left);
        }
        return true;
    }
};
