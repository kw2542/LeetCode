class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int shift = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (shift == 0) break;
            int res = digits[i] + shift;
            shift = res / 10;
            digits[i] = res % 10;
        }
        if (shift != 0) {
            digits.insert(digits.begin(), shift);
        }
        return digits;
    }
};