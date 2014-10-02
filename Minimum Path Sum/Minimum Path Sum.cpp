class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> sum(M);
        sum[0] = vector<int>(N);
        sum[0][0] = grid[0][0];
        for (int i = 1; i < M; i++) {
            sum[i] = vector<int>(N);
            sum[i][0] = sum[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < N; i++) {
            sum[0][i] = sum[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }
        return sum[M - 1][N - 1];
    }
};