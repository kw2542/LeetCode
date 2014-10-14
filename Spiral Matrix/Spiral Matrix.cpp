class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int length = matrix.size();
        int width = matrix[0].size();
        for (int i = 0; i * 2 < length && i * 2 < width; ++i) {
            for (int j = i; j < width - i; ++j)
                res.push_back(matrix[i][j]);
            for (int j = i + 1; j < length - i; ++j)
                res.push_back(matrix[j][width - i - 1]);
            if(length - 2 * i == 1 || width - 2 * i == 1)
                break;
            for (int j = width - i - 2; j >= i; --j)
                res.push_back(matrix[length - i - 1][j]);
            for (int j = length - i - 2; j > i; --j)
                res.push_back(matrix[j][i]);
         }
         return res;
    }
};