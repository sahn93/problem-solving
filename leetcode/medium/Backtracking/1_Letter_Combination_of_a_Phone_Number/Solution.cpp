class Solution {
public:
    vector<string> charsfornum(int i) {
        char head;
        vector<string> chars;
        if (i<7) {
            head = 'a' + 3*(i-2);
            for (int i=0; i<3; i++) {
                chars.push_back(string(1, head+i));
            }
        } else if (i==7) {
            head = 'p';
            for (int i=0; i<4; i++) {
                chars.push_back(string(1, head+i));
            }
        } else if (i==8) {
            head = 't';
            for (int i=0; i<3; i++) {
                chars.push_back(string(1, head+i));
            }
        } else {
            head = 'w';
            for (int i=0; i<4; i++) {
                chars.push_back(string(1, head+i));
            }
        }
        return chars;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size()==0)
            return res;
        if (digits.size()==1)
            return charsfornum(digits[0]-'0');
        
        string last = digits.substr(1);
        vector<string> lastcomb = letterCombinations(last);   
        vector<string> chars = charsfornum(digits[0]-'0');
        for (string& s: lastcomb) {
            for (string& c: chars) {
                res.push_back(c + s);
            }
        }
        return res;
    }
};
