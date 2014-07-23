public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        int len = A.length + B.length; 
        if (len % 2 == 0) 
            return ((double)findKthSortedArrays(A, 0, B, 0, len/2) + (double)findKthSortedArrays(A, 0, B, 0, len/2 + 1)) / 2;
        else 
            return (double)findKthSortedArrays(A, 0, B, 0, len/2 + 1);
    }
    private double findKthSortedArrays(int A[], int startOfA, int B[], int startOfB, int k) {
        if (startOfA >= A.length) return B[startOfB + k - 1];
        if (startOfB >= B.length) return A[startOfA + k - 1];
        
        if (k == 1) return Math.min(A[startOfA], B[startOfB]);
        
        int keyA;
        int keyB;
        if (startOfA + k/2 -1 >= A.length) keyA = Integer.MAX_VALUE;
        else keyA = A[startOfA + k/2 -1];
        if (startOfB + k/2 -1 >= B.length) keyB = Integer.MAX_VALUE;
        else keyB = B[startOfB + k/2 -1];
        
        if (keyA < keyB) return findKthSortedArrays(A, startOfA + k/2, B, startOfB, k - k/2 );
        else return findKthSortedArrays(A, startOfA, B, startOfB + k/2, k - k/2);
    }
}