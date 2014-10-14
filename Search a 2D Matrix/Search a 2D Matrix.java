public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        else return binarySearchMatrix(matrix, 0, matrix.length * matrix[0].length - 1, target);
    }
    private boolean binarySearchMatrix(int[][] matrix, int start, int end, int target) {
        if (start > end) return false;
        int mid = (start + end) / 2;
        int num = getNum(matrix, mid);
        if (num == target) return true;
        else if (num < target) return binarySearchMatrix(matrix, mid + 1, end, target);
        else return binarySearchMatrix(matrix, start, mid - 1, target);
    }
    private int getNum(int[][] matrix, int index) {
        return matrix[index / matrix[0].length][index % matrix[0].length];
    }
}