class Solution {
public:
    string decodeString(string s) {
        string res;
        int brackets = 0;
        int numstart = 0;
        int repeat = 0;
        int strstart;
        for (int i=0; i<s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                continue;
            } else if (s[i] == '[') {
                brackets++;
                if (brackets == 1) {
                    repeat = stoi(s.substr(numstart, i-numstart));
                    strstart = i+1;
                }
            } else if (s[i] == ']') {
                brackets--;
                if (brackets == 0) {
                    string inside = decodeString(s.substr(strstart, i-strstart));
                    while (repeat--) {
                        res += inside;
                    }
                    numstart = i+1;    
                }
            } else if (brackets == 0) {
                res += s.substr(i, 1);
                numstart++;
            }
        }
        return res;
    }
};
