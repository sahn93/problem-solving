class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;
        unordered_set<string> small, big;
        small.insert(beginWord);
        big.insert(endWord);
        int dist = 1;
        while (!small.empty() && !big.empty()) {
            dist++;
            if (small.size() > big.size()) {
                swap(small, big);
            }
            unordered_set<string> next;
            for (auto it = small.begin(); it != small.end(); it++) {
                string word = *it;
                for (int i=0; i<word.size(); i++) {
                    char orig = word[i];
                    for (char c='a'; c<='z'; c++) {
                        word[i] = c;
                        if (big.count(word) > 0) {
                            return dist;
                        }
                        if (wordSet.count(word) > 0) {
                            next.insert(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            swap(small, next);
        }
        
        return 0;
    }
};
