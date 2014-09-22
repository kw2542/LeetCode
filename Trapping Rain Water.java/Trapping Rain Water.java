public class Solution {
    public int trap(int[] A) {
        int max = -1;
        int max_index = -1;
        int prev = 0;
        int res = 0;
        
        for (int i = 0; i < A.length; ++i) {
            if (max < A[i]) {
                max = A[i];
                max_index = i;
            }
        }
        
        prev = 0;
        for (int i = 0; i < max_index; ++i) {
            if (A[i] > prev) {
                res += (A[i] - prev) * (max_index - i);
                prev = A[i];
            }
            res -= A[i];
        }
        
        prev = 0;
        for (int i = A.length - 1; i > max_index; --i) {
            if (A[i] > prev) {
                res += (A[i] - prev) * (i - max_index);
                prev = A[i];
            }
            res -= A[i];
        }
        
        return res;
    }
}