class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int lastlast = 1;
        int last = 1;
        int now = 0;
        for (int i = 1; i < n; ++i) {
            now = lastlast + last;
            lastlast = last;
            last = now;
        }
        return now;
    }
};