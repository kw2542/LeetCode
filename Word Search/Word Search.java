public class Solution {
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0) return false;
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == word.charAt(0)) {
                    if (existHelper(new boolean[board.length][board[0].length], i, j, board, 0, word)) return true;
                }
            }
        }
        return false;
    }
    private boolean existHelper(boolean[][] used, int x, int y, char[][] board, int start, String word) {
        if (word == null || start == word.length()) return true;
        if (x < 0 || x >= board.length || y < 0 || y >= board[x].length || 
            board[x][y] != word.charAt(start) || 
            used[x][y]) return false;
        boolean res = false;
        used[x][y] = true;
        if (existHelper(used, x + 1, y, board, start + 1, word) || 
            existHelper(used, x, y + 1, board, start + 1, word) || 
            existHelper(used, x - 1, y, board, start + 1, word) || 
            existHelper(used, x, y - 1, board, start + 1, word)) return true;
        used[x][y] = false;
        return false;
    }
}

