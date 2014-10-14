class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) return false;
        else return binarySearchMatrix(matrix, 0, matrix.size() * matrix[0].size() - 1, target);
    }
private:
    bool binarySearchMatrix(vector<vector<int> > &matrix, int start, int end, int target) {
        if (start > end) return false;
        int mid = (start + end) / 2;
        int num = getNum(matrix, mid);
        if (num == target) return true;
        else if (num < target) return binarySearchMatrix(matrix, mid + 1, end, target);
        else return binarySearchMatrix(matrix, start, mid - 1, target);
    }
    int getNum(vector<vector<int> > &matrix, int index) {
        return matrix[index / matrix[0].size()][index % matrix[0].size()];
    }
};