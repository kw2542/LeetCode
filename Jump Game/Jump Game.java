public class Solution {
    public boolean canJump(int[] A) {
        int lastTrue = A.length - 1;
        for (int i = A.length - 1; i >= 0; --i) {
            if (i + A[i] >= lastTrue) lastTrue = i;
        }
        return lastTrue == 0;
    }
}