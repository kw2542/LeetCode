public class Solution {
    public String addBinary(String a, String b) {
        int m = a.length();
        int n = b.length();
        int len = Math.max(m, n);
        int shift = 0;
        int res = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; ++i) {
            --m;
            --n;
            if (m >= 0 && n >= 0) {
                res = a.charAt(m) + b.charAt(n) + shift - '0' - '0';
            } else if (m >= 0) {
                res = a.charAt(m) - '0' + shift;
            } else {
                res = b.charAt(n) - '0' + shift;
            }
            shift = res / 2;
            res = res % 2;
            sb.insert(0, res);
        }
        if (shift != 0) sb.insert(0, shift);
        return sb.toString();
    }
}