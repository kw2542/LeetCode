public class Solution {
    public int jump(int[] A) {
        int maxRange = 0;
        int lastBoundry = 0;
        int steps = 0;
        for (int i = 0; i < A.length; ++i) {
            if (i > lastBoundry) {
                ++steps;
                lastBoundry = maxRange;
            }
            maxRange = Math.max(maxRange, i + A[i]);
        }
        return steps;
    }
}