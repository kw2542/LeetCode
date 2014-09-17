class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        for (int i = 0; i < 9; ++i) {
            bool map[9] = {false};
            for (char c : board[i]) {
                if (c != '.') {
                    if (map[c - '1'] == true) return false;
                    else map[c - '1'] = true;
                }
            }
        } 
        for (int i = 0; i < 9; ++i) {
            bool map[9] = {false};
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (c != '.') {
                    if (map[c - '1'] == true) return false;
                    else map[c - '1'] = true;
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                bool map[9] = {false};
                for (int k = 0; k < 9; ++k) {
                    char c = board[i + k % 3][j + k / 3];
                    if (c != '.') {
                        if (map[c - '1'] == true) return false;
                        else map[c - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};