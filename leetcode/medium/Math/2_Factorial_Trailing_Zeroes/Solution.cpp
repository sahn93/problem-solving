class Solution {
public:
    int trailingZeroes(int n) {
        // count number of 10s
        // thus, number of 5s until n.
        int fives = 0;
        while (n > 0) {
            fives += n/5;
            n /= 5;
        }
        return fives;
    }
};
