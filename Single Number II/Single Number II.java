public class Solution {
    public int singleNumber(int[] A) {
        int[] bit = new int[32];
        int res = 0;
        for (int shift = 0; shift < 32; ++shift) {
            for (int i : A) {
                bit[shift] += (i >> shift) & 0x1;
                bit[shift] %= 3;
            }
            res |= (bit[shift] << shift);
        }
        return res;
    }
}