public class Solution {
    public int removeDuplicates(int[] A) {
        if (A.length == 0) return 0;
        int lastInput = A[0];
        int count = 1;
        for (int i = 1; i < A.length; ++i) {
            if (lastInput != A[i]) {
                lastInput = A[i];
                A[count] = A[i];
                ++count;
            }
        }
        return count;
    }
}