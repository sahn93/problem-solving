/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // bfs
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front(); 
            q.pop();
            
            if (node == NULL) {
                res += "null,";
            } else {
                res += to_string(node->val);
                res += ",";    
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        res = "[" + res.substr(0, res.length()-1) + "]";
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // remove bracket
        data = data.substr(1, data.length()-2);
        vector<TreeNode*> nodes;
        while (data.find(",") != string::npos) {
            string token = data.substr(0, data.find(","));
            if (token == "null") {
                nodes.push_back(NULL);
            } else {
                TreeNode* node = new TreeNode(stoi(token));
                nodes.push_back(node);
            }
            data = data.substr(data.find(",") + 1, data.length()-1);
        }
        if (data == "null") {
            if (nodes.size() == 0) return NULL;
            nodes.push_back(NULL);
        } else {
            TreeNode* node = new TreeNode(stoi(data));
            nodes.push_back(node);
        }
        
        
        queue<TreeNode*> q;
        q.push(nodes[0]);
        int i = 0;
        int j = 1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            node->left = nodes[j++];
            if (node->left != NULL) {
                q.push(node->left);
            }
            node->right = nodes[j++];
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
