class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> absum;
        int res = 0;
        int n = A.size();
        for (int a: A) {
            for (int b: B) {
                int sum = a+b;
                if (absum.count(sum)>0) {
                    absum[sum]++;
                } else {
                    absum[sum] = 1;
                }
            }
        }
        for (int c: C) {
            for (int d: D) {
                int sum = c+d;
                res += absum[-sum];
            }
        }
        return res;
    }
};
