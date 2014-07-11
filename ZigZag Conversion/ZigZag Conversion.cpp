class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        const int key = 2 * nRows - 2;
        const int size = s.size();
        string res("");
        for (int i = 0; i < nRows; ++i) {
            for (int j = i; j < size; j += key) {
                res += s[j];
                if (i > 0 && i < nRows - 1 && j + key - 2 * i < size) res += s[j + key - 2 * i]; 
            }
        }
        return res;
    }
};