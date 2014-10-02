/*
 * The following solution is correct but we may get overflow
class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long total = m + n - 2;
        unsigned long long num = min(m - 1 , n - 1);
        unsigned long long numerator = 1;
        unsigned long long denominator = 1;
        for (unsigned long long i = 1; i <= num; ++i) {
            denominator *= i;
        }
        for (unsigned long long i = total - num + 1; i <= total; ++i) {
            numerator *= i;
        }
        return numerator / denominator;
    }
};
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; ++i) {
            dp[i] = vector<int>(n);
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};