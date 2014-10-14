public class Solution {
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return;
        Set<Integer> row = new HashSet<Integer>();
        Set<Integer> col = new HashSet<Integer>();
        for (int i = 0; i < matrix.length; ++i) {
            for (int j = 0; j < matrix[0].length; ++j) {
                if (matrix[i][j] == 0) {
                    row.add(i);
                    col.add(j);
                }
            }
        }
        for (Integer i : row) {
            for (int j = 0; j < matrix[0].length; ++j) {
                matrix[i][j] = 0;
            }
        }
        for (Integer i : col) {
            for (int j = 0; j < matrix.length; ++j) {
                matrix[j][i] = 0;
            }
        }
    }
}