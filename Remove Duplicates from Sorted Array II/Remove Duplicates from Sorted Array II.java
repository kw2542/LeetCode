public class Solution {
    public int removeDuplicates(int[] A) {
        if (A.length < 2) return A.length;
        int count = 2;
        for (int i = 2; i < A.length; ++i) {
            if (A[i] == A[count - 1] && A[i] == A[count - 2]) continue;
            else A[count++] = A[i];
        }
        return count;
    }
}