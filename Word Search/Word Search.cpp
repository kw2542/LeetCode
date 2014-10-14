class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) return false;
        vector<vector<bool> > used;
        for (int i = 0; i < board.size(); ++i) {
            used.push_back(vector<bool>(board[i].size(), false));
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (existHelper(used, i, j, board, 0, word)) return true;
                }
            }
        }
        return false;
    }
    bool existHelper(vector<vector<bool> > &used, int x, int y, vector<vector<char> > &board, int start, string word) {
        if (start == word.size()) return true;
        if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[x].size() ||
            board[x][y] != word[start] ||
            used[x][y]) return false;
        used[x][y] = true;
        if (existHelper(used, x + 1, y, board, start + 1, word) ||
            existHelper(used, x, y + 1, board, start + 1, word) ||
            existHelper(used, x - 1, y, board, start + 1, word) ||
            existHelper(used, x, y - 1, board, start + 1, word)) return true;
        used[x][y] = false;
        return false;
    }
};