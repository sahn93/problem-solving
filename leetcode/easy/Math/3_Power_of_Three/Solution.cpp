class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<1)
            return false;
        while(n>1) {
            if (n%3==0) {
                n/=3;
            } else {
                return false;
            }
        }
        return true;
        // recursive version:
        // return (n>0) && ((n==1) || (n%3==0 && isPowerOfThree(n/3)));
    }
};
