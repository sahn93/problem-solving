class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool is_neg = (dividend > 0) ^ (divisor > 0);
        
        unsigned int dvd = abs(dividend);
        unsigned int dvs = abs(divisor);
        
        int pow = 1;
        int ans = 0;
        
        while (dvs < (dvd >> 1)) {
            dvs <<= 1;
            pow <<= 1;
        }
        
        while (dvs > 0) {
            while (dvd >= dvs) {
                dvd -= dvs;
                ans += pow;
            }
            dvs >>= 1;
            pow >>= 1;
        }
        
        return is_neg ? -ans : ans;
    }
};
