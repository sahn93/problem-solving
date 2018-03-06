/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        // check if next level exists
        while (root->left) {
            TreeLinkNode *thislevel = root;
            while(thislevel) {
                thislevel->left->next = thislevel->right;
                if (thislevel->next) {
                    thislevel->right->next = thislevel->next->left;
                }
                thislevel = thislevel->next;
            }
            root = root->left;
        }
    }
};
