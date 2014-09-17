public class Solution {
    public boolean isValidSudoku(char[][] board) {
        if (board == null || board.length != 9 || board[0].length != 9) return false;
        for (int i = 0; i < 9; ++i) {
            boolean[] map = new boolean[9];
            for (char c : board[i]) {
                if (c != '.') {
                    if (map[c - '1'] == true) return false;
                    else map[c - '1'] = true;
                }
            }
        } 
        for (int i = 0; i < 9; ++i) {
            boolean[] map = new boolean[9];
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
                boolean[] map = new boolean[9];
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
}