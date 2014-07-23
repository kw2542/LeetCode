public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        int index = 0;
        while (true) {
            if (index >= strs[0].length()) return strs[0];
            for (int i = 1; i < strs.length; ++i)
                if (strs[i].length() < index + 1 || strs[0].charAt(index) != strs[i].charAt(index))
                    return strs[0].substring(0, index);
            ++index;
        }
    }
}