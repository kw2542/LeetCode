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
    static bool compare(Interval a, Interval b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 1) return intervals; 
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        Interval last = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            Interval cur = intervals[i];
            if (last.end >= cur.start) {
                last.end = max(last.end, cur.end);
            } else {
                res.push_back(last);
                last = cur;
            }
        }
        res.push_back(last);
        return res;
    }
};