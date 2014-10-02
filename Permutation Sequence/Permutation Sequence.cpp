class Solution {
public:
    string getPermutation(int n, int k) {
        int totalNum = 1;
        for (int i = 1; i <= n; ++i) {
            totalNum *= i;
        }
        k = k - 1; // set the start to be 0;
        string res = "";
        vector<int> validNumber;
        for (int i = 1; i <= n; ++i) {
            validNumber.push_back(i);
        }
        for (int i = n; i > 0; --i) {
            totalNum /= i;
            int index = k / totalNum;
            res += to_string(validNumber[index]);
            validNumber.erase(validNumber.begin() + index);
            k = k % totalNum;
        }
        return res;
    }
};