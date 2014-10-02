/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
		List<Interval> res = new ArrayList<Interval>();
        if (intervals == null || intervals.size() == 0) {
            res.add(newInterval);
            return res;
        }
        boolean in = false;
        for (int i = 0; i < intervals.size(); ++i) {
            Interval cur = intervals.get(i);
            if (cur.start <= newInterval.start && cur.end >= newInterval.start) {
                newInterval.start = cur.start;
                newInterval.end = Math.max(cur.end, newInterval.end);
            } else if (cur.start >= newInterval.start && cur.start <= newInterval.end) {
                newInterval.end = Math.max(cur.end, newInterval.end);
            } else {
                if (!in && cur.start > newInterval.end) {
                    in = true;
                    res.add(newInterval);
                }
                res.add(cur);
            }
        }
        if (!in) res.add(newInterval);
        return res;
    }
}