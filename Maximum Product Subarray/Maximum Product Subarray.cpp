class Solution {
public:
    int maxProduct(int A[], int n) {
        int res = INT_MIN;
        int mx = 0;
        int mn = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = mx;
            if (mx != 0) mx = max(A[i], max(mx * A[i], mn * A[i]));
            else mx = A[i];
            if (mn != 0) mn = min(A[i], min(tmp * A[i], mn * A[i]));
            else mn = A[i];
            res = max(res, mx);
        }
        return res;
    }
};