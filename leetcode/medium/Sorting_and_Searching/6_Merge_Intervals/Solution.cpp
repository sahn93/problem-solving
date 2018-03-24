/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), [ ](const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });
        int start = 0;
        vector<Interval> res;
        while (start < intervals.size()) {
            int maximum = intervals[start].end;
            int end = start;
            while (end < intervals.size() - 1 && maximum >= intervals[end+1].start) {
                maximum = max(maximum, intervals[++end].end);
            }
//            cout << start << end << '\n';
            res.push_back(Interval(intervals[start].start, maximum));
            start = end + 1;
        }
        return res;
    }
    
};
