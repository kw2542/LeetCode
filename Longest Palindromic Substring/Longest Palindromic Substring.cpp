class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1000][1000] = {false};
        const int size = s.size();
        for (int i = 0; i < size; ++ i) {
            dp[i][i] = true;
            if(i < size - 1) dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int offset = 2; offset < size; ++offset) {
            for (int start = 0; start < size - 1; ++ start) {
                if (start + offset >= size) break;
                dp[start][start + offset] = dp[start + 1][start + offset - 1] && (s[start] == s[start + offset]);
            }
        }
        for (int len = size; len >= 0; --len) {
            for (int start = 0; start < size- len + 1; ++ start) {
                if (dp[start][start + len - 1] == true) {
                    return s.substr(start, len);
                }
            }
        }
        return "";
    }
};