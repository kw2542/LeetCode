class Solution {
public:
    bool canJump(int A[], int n) {
        int lastTrue = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (i + A[i] >= lastTrue) lastTrue = i;
        }
        return lastTrue == 0;
    }
};