public class Solution {
    public int firstMissingPositive(int[] A) {
        for (int i = 0; i < A.length; ++i) {
            while (A[i] > 0 && A[i] != i + 1 && A[i] < A.length) {
                int tmp = A[A[i] - 1];
                if (A[i] == tmp) break;
                A[A[i] - 1] = A[i];
                A[i] = tmp;
            }
        }
        for (int i = 0; i < A.length; ++i) {
            if (A[i] != i + 1) return i + 1;
        }
        return A.length + 1;
    }
}