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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if (root==NULL)
            return ret;
        else
            q.push(root);
        while (!q.empty()) {
            vector<int> thislevel;
            queue<TreeNode*> nextq;
            while (!q.empty()) {
                TreeNode* e = q.front();
                q.pop();
                thislevel.emplace_back(e->val);
                if(e->left)
                    nextq.push(e->left);
                if(e->right)
                    nextq.push(e->right);
            }
            ret.emplace_back(thislevel);
            q = nextq;
        }
        return ret;
    }
};
