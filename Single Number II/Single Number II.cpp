class Solution {
public:
    int singleNumber(int A[], int n) {
        int *bit = new int[32];
        int res = 0;
        for (int shift = 0; shift < 32; ++shift) {
            bit[shift] = 0;
            for (int i = 0; i < n; ++i) {
                bit[shift] += (A[i] >> shift) & 0x1;
                bit[shift] %= 3;
            }
            res |= (bit[shift] << shift);
        }
        return res;
    }
};