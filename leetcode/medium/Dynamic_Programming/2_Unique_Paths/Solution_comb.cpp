class Solution {
public:
    int uniquePaths(int m, int n) {
        // (m+n-2 C m-1)
        long long int res = 1;
        int head = m+n-2;
        int num = min(m-1, n-1);
        while (num > 0) {
            res *= head;
            head--;
            num--;
        }
        num = min(m-1, n-1);
        while (num > 0) {
            res /= num;
            num--;
        }
        return res;
    }
};
