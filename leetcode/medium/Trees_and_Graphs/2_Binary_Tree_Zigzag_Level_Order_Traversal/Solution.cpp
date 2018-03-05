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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool startleft = true;
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> layer;
        layer.push(root);
        
        while(!layer.empty()) {
            int layerSize = layer.size();
            vector<int> layervec(layerSize);
            for (int i=0; i<layerSize; i++) {
                TreeNode* node = layer.front();
                layer.pop();
                if (startleft) {
                    layervec[i] = node->val;
                } else {
                    layervec[layerSize-i-1] = node->val;
                }
                if (node->left) layer.push(node->left);
                if (node->right) layer.push(node->right);
            }
            startleft = !startleft;
            res.emplace_back(layervec);
        }
        return res;
    }
};
