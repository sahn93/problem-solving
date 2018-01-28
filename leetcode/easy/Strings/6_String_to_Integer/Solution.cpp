class Solution {
public:
    int myAtoi(string str) {
        int start=0;
        bool pos=true;
        long long res=0;
        while (str[start] == ' ')
            start++;
        if (str[start]=='+')
            start++;
        else if (str[start]=='-') {
            pos = false;
            start++;
        }
        if (start==str.size())
            return 0;
        
        while (start != str.size() && str[start]>='0' && str[start] <='9') {
            res = res*10 + str[start]-'0';
            if (pos && res > INT_MAX)
                return INT_MAX;
            else if (!pos && -res < INT_MIN)
                return INT_MIN;
            start++;
        }
        return pos ? res : -res;
    }
};
