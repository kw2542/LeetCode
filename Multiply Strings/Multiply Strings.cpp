class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len3 = len1 + len2;
        vector<int> res(len3, 0);
        for (int i = len1 - 1; i >= 0; --i) {
            int carry = 0;
            int j = len2 - 1;
            for (j = len2 - 1; j >= 0; --j) {
                int product = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1] +  carry;
                res[i + j + 1] = product % 10;
                carry = product / 10;
            }
            res[i + j + 1] = carry;
        }
        int start = 0;
        while(res[start] == 0 && start < len3 - 1) ++start;
        string ss = "";
        while(start < len3) ss += to_string(res[start++]);
        return ss;
    }
};