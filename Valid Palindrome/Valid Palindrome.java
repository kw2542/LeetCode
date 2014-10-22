public class Solution {
    public boolean isPalindrome(String s) {
        char[] c = s.toCharArray();
        int start = 0;
        int end = c.length - 1;
        while (start < end) {
            if (false == isAlphanumeric(c[start])) ++start;
            else if (false == isAlphanumeric(c[end])) --end;
            else if (Character.toLowerCase(c[start]) == Character.toLowerCase(c[end])) {
                ++start;
                --end;
            } else return false;
        }
        return true;
    }
    private boolean isAlphanumeric (char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z');
    }
}