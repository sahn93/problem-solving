class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        vector<string> n(nums.size());
        for (int i=0; i<nums.size(); i++) {
            n[i] = to_string(nums[i]);
        }
        sort(n.begin(), n.end(), [](string &a, string &b) { return a + b > b + a; });
        for (string &s: n) {
            res += s;
        }
        return res[0] == '0' ? "0" : res;
    }
};
