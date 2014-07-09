public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = 0;
        int max = 0;
        int[] map = new int[256];
        for (int i = 0; i < 256; ++i) map[i] = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (map[s.charAt(i)] != -1 && map[s.charAt(i)] >= start) {
                max = max > i - start ? max : i - start;
                start = map[s.charAt(i)] + 1;
            }
            map[s.charAt(i)] = i;
        }
        max = max > s.length() - start ? max : s.length() - start;
        return max;
    }
}