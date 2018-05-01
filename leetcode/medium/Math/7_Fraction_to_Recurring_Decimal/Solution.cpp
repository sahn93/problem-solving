class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // denominator: 9...0...
        string ans;
        if (numerator == INT_MIN && denominator == -1) {
            unsigned int n = -INT_MIN;
            return to_string(n);
        }
        if (numerator == 0) return "0";
        bool neg = (numerator >= 0) ^ (denominator >= 0);
        if (neg) {
            ans += "-";
        }
        unsigned int nmr = abs(numerator);
        unsigned int den = abs(denominator);
        
        unsigned int quote = nmr / den;
        ans += to_string(quote);
        long long int rem = nmr % den;
        if (rem == 0) return ans;
        ans += ".";
        
        // detect start of cycle
        int d = den;
        int twos = 0;
        int fives = 0;
        while (d % 2 == 0) {
            if (nmr % 2 == 0) {
                nmr/=2;
            } else {
                twos++;
            }
            d/=2;
        }
        while (d % 5 == 0) {
            if (nmr % 5 == 0) {
                nmr /= 5;
            } else {
                fives++;
            }
            d/=5;
        }
        int nocycle = max(twos, fives);
        
        // Add no cycle part.
        while (nocycle) {
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
            nocycle--;
        }
        if (rem == 0) return ans;
        
        // cycles
        ans += '(';
        
        int r = rem*10;
        ans += to_string(r / den);
        r %= den;
        while (r != rem) {
            r *= 10;
            ans += to_string(r / den);
            r %= den;
        }

        ans += ')';
        return ans;
    }
};
