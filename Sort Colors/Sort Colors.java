public class Solution {
    public void sortColors(int[] A) {
        int start = 0;
        int end = A.length - 1;
        for (int i = 0; i <= end; ++i) {
            if (A[i] == 0) {
                if (i > start) A[i--] = A[start];
                A[start++] = 0;
            } else if (A[i] == 2) {
                A[i--] = A[end];
                A[end--] = 2;
            }
        }
    }
}