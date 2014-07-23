public class Solution {
    public int atoi(String str) {
        if (str.length() == 0) return 0;
        char[] c = str.toCharArray();
        long res = 0;
        boolean isNegative = false;
        int i = 0;
        for (; i < c.length && c[i] == ' '; ++i) {
        }
        if (c[i] == '-') {
            isNegative = true;
            ++i;
        } else if (c[i] == '+') ++i;
        for (; i < c.length && c[i] >= '0' && c[i] <= '9'; ++i) {
            res = res * 10 + c[i] - '0';
            if (res > Integer.MAX_VALUE)  break;
        }
        if (isNegative) res = -res;
        if (res > Integer.MAX_VALUE) res = Integer.MAX_VALUE;
        else if (res < Integer.MIN_VALUE) res = Integer.MIN_VALUE;
        return (int)res;
    }
}