class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> res(k,0);
        for (int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        vector<pair<int, int>> elems(count.begin(), count.end());
        sort(elems.begin(), elems.end(),
                [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
                    return lhs.second > rhs.second; } );
        for (int i=0; i<k; i++) {
            res[i] = elems[i].first;
        }
        return res;
    }
};
