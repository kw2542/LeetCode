class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n; 
        if (len % 2 == 0) 
            return ((double)findKthSortedArrays(A, 0, m, B, 0, n, len/2) + (double)findKthSortedArrays(A, 0, m, B, 0, n, len/2 + 1)) / 2;
        else 
            return (double)findKthSortedArrays(A, 0, m, B, 0, n, len/2 + 1);
    }
    double findKthSortedArrays(int A[], int startOfA, int m, int B[], int startOfB, int n, int k) {
        if (startOfA >= m) return B[startOfB + k - 1];
        if (startOfB >= n) return A[startOfA + k - 1];
        
        if (k == 1) return min(A[startOfA], B[startOfB]);
        
        int keyA;
        int keyB;
        if (startOfA + k/2 -1 >= m) keyA = INT_MAX;
        else keyA = A[startOfA + k/2 -1];
        if (startOfB + k/2 -1 >= n) keyB = INT_MAX;
        else keyB = B[startOfB + k/2 -1];
        
        if (keyA < keyB) return findKthSortedArrays(A, startOfA + k/2, m, B, startOfB, n, k - k/2 );
        else return findKthSortedArrays(A, startOfA, m, B, startOfB + k/2, n, k - k/2);
    }
};