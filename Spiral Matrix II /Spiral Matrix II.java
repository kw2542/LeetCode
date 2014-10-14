public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int count = 1;
        for (int i = 0; i * 2 < n; ++i) {
            for (int j = i; j < n - i; ++j)
                res[i][j] = count++;
            for (int j = i + 1; j < n - i; ++j)
                res[j][n - i - 1] = count++;
            if (2 * i == n - 1) break;
            for (int j = n - i - 2; j >= i; --j)
                res[n - i - 1][j] = count++;
            for (int j = n - i - 2; j > i; --j)
                res[j][i] = count++;
        }
        return res;
    }
}