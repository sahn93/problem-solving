class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for (char c: tasks) {
            v[c-'A']++;
        }
        sort(v.begin(), v.end());
        int maxnum = v[25];
        int over = 0;
        for (int i=0; i<26; i++) {
            if (v[i] == maxnum) over++;
        }
        int len = tasks.size();
        return max(len, (maxnum - 1) * (n + 1) + over);
    }
};
