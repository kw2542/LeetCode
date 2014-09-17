class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        res.push_back(search(A, 0, n - 1, target, true));
        res.push_back(search(A, 0, n - 1, target, false));
        return res;
    }
    int search(int A[], int s, int e, int target, bool isLeft) {
        if (s > e) return -1;
        int mid = (s + e) / 2;
        if (A[mid] < target) return search(A, mid + 1, e, target, isLeft);
        else if (A[mid] > target) return search(A, s, mid - 1, target, isLeft);
        else {
            if (isLeft) {
                int res = search(A, s, mid - 1, target, isLeft);
                if (res != -1) return res;
                else return mid;
            } else {
                int res = search(A, mid + 1, e, target, isLeft);
                if (res != -1) return res;
                else return mid;
            }
        }
    }
};