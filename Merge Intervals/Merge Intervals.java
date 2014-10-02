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
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals == null || intervals.size() < 1) return intervals;
        List<Interval> res = new ArrayList();
        Collections.sort(intervals, new Comparator<Interval>() {
			@Override
			public int compare(Interval o1, Interval o2) {
				return o1.start - o2.start;
			}
		});
		Interval last = intervals.get(0);
		for (int i = 1; i < intervals.size(); ++i) {
		    Interval cur = intervals.get(i);
		    if (last.end >= cur.start) {
		        last.end = Math.max(last.end, cur.end);
		    } else {
		        res.add(last);
		        last = cur;
		    }
		}
		res.add(last);
        return res;
    }
}