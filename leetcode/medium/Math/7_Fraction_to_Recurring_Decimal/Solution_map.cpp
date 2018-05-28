class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long n = labs(numerator), d = labs(denominator);
        
        string res = "";
        bool neg = (numerator > 0 ^ denominator > 0);
        if (neg) res += "-";
        
        if (n % d == 0) {
            res += to_string(n/d);
            return res;
        }
        
        res += to_string(n/d) + ".";
        n %= d;
        
        unordered_map<int, int> mapping;
        while (n > 0) {
            if (mapping.count(n) == 0) {
                mapping[n] = res.length();
                n *= 10;
                res += to_string(n/d);
                n %= d;
            } else {
                res.insert(mapping[n], 1, '(');
                res += ")";
                break;
            }
        }
        return res;
    }
};
