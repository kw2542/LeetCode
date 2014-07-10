public class Solution {
    public String longestPalindrome(String s) {
    	final int LENGTH = s.length();
    	final char[] c = s.toCharArray();
        boolean[][] dp = new boolean[LENGTH][LENGTH];
        for (int i = 0; i < LENGTH; ++ i) {
            dp[i][i] = true;
            if(i < LENGTH - 1) dp[i][i + 1] = (c[i] == c[i + 1]);
        }
        for (int offset = 2; offset < LENGTH; ++offset) {
            for (int start = 0; start < LENGTH - 1; ++ start) {
                if (start + offset >= LENGTH) break;
                dp[start][start + offset] = dp[start + 1][start + offset - 1] && (c[start] == c[start + offset]);
            }
        }
        for (int len = LENGTH; len >= 0; --len) {
            for (int start = 0; start < LENGTH - len + 1; ++ start) {
                if (dp[start][start + len - 1] == true) {
                    return s.substring(start, start + len);
                }
            }
        }
        return "";
    }
}