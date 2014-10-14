public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return res;
        int length = matrix.length;
        int width = matrix[0].length;
        for (int i = 0; i * 2 < length && i * 2 < width; ++i) {
            for (int j = i; j < width - i; ++j)
                res.add(matrix[i][j]);
            for (int j = i + 1; j < length - i; ++j)
                res.add(matrix[j][width - i - 1]);
            if(length - 2 * i == 1 || width - 2 * i == 1)
                break;
            for (int j = width - i - 2; j >= i; --j)
                res.add(matrix[length - i - 1][j]);
            for (int j = length - i - 2; j > i; --j)
                res.add(matrix[j][i]);
         }
         return res;
    }
}