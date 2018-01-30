class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;
        if (needle.size()==0)
            return 0;
        int j;
        for (int i=0; i<=haystack.size()-needle.size(); i++) {
            j=0;
            while(haystack[i+j]==needle[j] && j < needle.size())
                j++;
            cout << j << endl;
            if (j==needle.size())
                return i;
        }
        return -1;
    }
};
