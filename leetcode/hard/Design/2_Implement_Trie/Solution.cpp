class Node {
public:    
    bool terminal = false;
    Node * child[26]; 
};

class Trie {
public:
    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        for (int i=0; i<word.size(); i++) {
            if (curr->child[word[i] - 'a'] == nullptr) {
                curr->child[word[i] - 'a'] = new Node();
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for (int i=0; i<word.size(); i++) {
            if (curr->child[word[i] - 'a'] == nullptr) {
                return false;
            } else {
                curr = curr->child[word[i] - 'a'];
            }
        }
        return curr->terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        for (int i=0; i<prefix.size(); i++) {
            if (curr->child[prefix[i] - 'a'] == nullptr) {
                return false;
            } else {
                curr = curr->child[prefix[i] - 'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
