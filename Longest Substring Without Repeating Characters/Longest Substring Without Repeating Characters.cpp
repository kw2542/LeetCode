class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int start = 0;
        int map[256];
        for (int i = 0; i < 256; ++i) map[i] = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] != -1 && map[s[i]] >= start) {
                max = max > i - start ? max : i - start;
                start = map[s[i]] + 1;
            }
            map[s[i]] = i;
        }
        if (max < s.size() - start) max = s.size() - start;
        return max;
    }
};