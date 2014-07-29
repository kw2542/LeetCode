class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int lastInput = A[0];
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (lastInput != A[i]) {
                A[count] = A[i];
                lastInput = A[i];
                count++;
            }
        }
        return count;
    }
};