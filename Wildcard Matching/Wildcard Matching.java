public class Solution {
	public boolean isMatch(String s, String p) {
        return isMatch(s.toCharArray(), p.toCharArray());
    }
    public boolean isMatch(char[] s, char[] p) {
        int n = 0;
        int prev_n = 0;
        int m = 0;
        int prev_m = 0;
        boolean star = false;
        while (n < s.length) {
            if (m >= p.length) {
                if (star) {
                    n = prev_n;
                    m = prev_m;
                    ++prev_n;
                } else return false;
            } else if (p[m] == '*') {
                star = true;
                while (m < p.length && p[m] == '*') ++m;
                if (m == p.length) return true;
                prev_m = m;
                prev_n = n;
            } else if (p[m] == '?' || s[n] == p[m]) {
                ++n;
                ++m;
            } else if (star) {
                n = prev_n;
                m = prev_m;
                ++prev_n;
            } else return false;
        }
        while (m < p.length && p[m] == '*') ++m;
        return m == p.length;
    }
}