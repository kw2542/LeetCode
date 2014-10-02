class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int len = max(m, n);
        int shift = 0;
        int res = 0;
        string s = "";
        for (int i = 0; i < len; ++i) {
            --m;
            --n;
            if (m >= 0 && n >= 0) {
                res = a[m] + b[n] + shift - '0' - '0';
            } else if (m >= 0) {
                res = a[m] - '0' + shift;
            } else {
                res = b[n] - '0' + shift;
            }
            shift = res / 2;
            res = res % 2;
            s = to_string(res) + s;
        }
        if (shift != 0) s = to_string(shift) + s;
        return s;
    }
};