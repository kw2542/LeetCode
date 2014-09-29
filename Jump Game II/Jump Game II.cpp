class Solution {
public:
    int jump(int A[], int n) {
        int maxRange = 0;
        int lastBoundry = 0;
        int steps = 0;
        for (int i = 0; i < n; ++i) {
            if (i > lastBoundry) {
                ++steps;
                lastBoundry = maxRange;
            }
            maxRange = max(maxRange, i + A[i]);
        }
        return steps;
    }
};