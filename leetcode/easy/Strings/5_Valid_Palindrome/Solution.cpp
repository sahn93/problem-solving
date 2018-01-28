class Solution {
public:
    bool isPalindrome(string s) {
        // convert to a single word in lowercase.
        string str = "";
        for (char &c: s) {
            if ((c <= 'z'&& c>='a')|| (c <= 57 && c>=48)) {
                str += c;
            } else if (c <= 'Z' && c >= 'A') {
                str += (c+32);
            }
        }
        for (int i=0; i<str.size()/2; i++) {
            if (str[i] != str[str.size()-1-i])
                return false;
        }
        cout << str;
        return true;
    }
};
