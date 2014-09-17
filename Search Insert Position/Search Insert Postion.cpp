class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return searchInsert(A, 0, n - 1, target);
    }
    int searchInsert(int A[], int s, int e, int target) {
        if (s > e) return e + 1;
        int mid = (s + e) / 2;
        if (A[mid] == target) return mid;
        else if (A[mid] > target) return searchInsert(A, s, mid - 1, target);
        else return searchInsert(A, mid + 1, e, target);
    }
};