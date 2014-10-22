public class Solution {
    public int maxProduct(int[] A) {
        if (A == null || A.length == 0) return 0;
        int res = Integer.MIN_VALUE;
        int max = 0;
        int min = 0;
        for (int i = 0; i < A.length; ++i) {
            int tmp = max;
            if (max != 0) max = Math.max(A[i], Math.max(max * A[i], min * A[i]));
            else max = A[i];
            if (min != 0) min = Math.min(A[i], Math.min(tmp * A[i], min * A[i]));
            else min = A[i];
            res = Math.max(res, max);
        }
        return res;
    }
}