class Solution {
public:
    int search(int A[], int n, int target) {
        return search(A, 0, n - 1, target);
    }
    int search(int A[], int s, int e, int target) {
        if (s > e) return -1;
        int mid = (s + e) / 2;
        if (target == A[mid]) return mid;
        if (A[s] < A[mid]) {
            if (A[s] <= target && A[mid] > target) return search(A, s, mid - 1, target);
            else return search(A, mid + 1, e, target);
        } else if (A[mid] < A[e]) {
            if (A[mid] < target && A[e] >= target) return search(A, mid + 1, e, target);
            else return search(A, s, mid - 1, target);
        } else {
            int res = search(A, s, mid - 1, target);
            if (res != -1) return res;
            else return search(A, mid + 1, e, target);
        }
    }
};