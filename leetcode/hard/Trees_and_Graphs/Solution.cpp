class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> Q;
        Q.push(beginWord);
        wordSet.erase(beginWord);
        int dist = 1;
        
        while(!Q.empty()) {
            queue<string> next;
            while(!Q.empty()) {
                string word = Q.front();
                Q.pop();
                // cout << word << endl;
                if (word == endWord) return dist;
                string orig = word;
                for (int i=0; i<word.size(); i++) {
                    for (char c='a'; c<='z'; c++) {
                        word = orig;
                        word[i] = c;
                        if (wordSet.count(word) > 0) {
                            wordSet.erase(word);
                            next.push(word);
                        }
                    }
                }
            }
            swap(Q, next);
            dist++;
        }
        return 0;
    }
};
