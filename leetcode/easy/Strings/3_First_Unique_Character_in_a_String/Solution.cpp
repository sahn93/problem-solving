class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alp(26, 0);
        
        for (char c : s) {
            alp[c-'a']++;
        }
        for (int i=0; i<s.size(); i++) {
            if (alp[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
