class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        
        double res = x, num = x;
        if (n < 0) {
            n = -n;
            res = 1/res;
            num = res;
        }
        
        int pow = 1;
        while (n/2 >= pow) {
            res *= res; 
            pow *= 2;
        }
        return res * myPow(num, n-pow);
    }
};
