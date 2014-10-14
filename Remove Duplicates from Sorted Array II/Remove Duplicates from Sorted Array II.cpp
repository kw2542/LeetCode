class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int count = 2;
        for (int i = 2; i < n; ++i) {
            if (A[i] == A[count - 1] && A[i] == A[count - 2]) continue;
            else A[count++] = A[i];
        }
        return count;
    }
};