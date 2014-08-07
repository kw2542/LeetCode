class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        for (int i = size - 1; i > 0; --i) {
            if (num[i] > num[i - 1]) {
                int j = i;
                while (j < size && num[j] > num[i - 1]) ++j;
                int t = num[j - 1];
                num[j - 1] = num[i - 1];
                num[i - 1] = t;
                sort(num.begin() + i, num.end());
                break;
            }
            if (i == 1) sort(num.begin(), num.end());
        }
    }
};