public class Solution {
    public boolean isMatch(String s, String p) {
        if (s.length() == 0 && p.length() == 0) return true;
        else if (p.length() == 0) return false;
        else if (s.length() == 0) {
            if (p.length() > 1 && p.charAt(1) == '*') return isMatch(s, p.substring(2));
            else return false;
        }
        if (p.length() > 1 && p.charAt(1) == '*')
            if (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') return isMatch(s, p.substring(2)) || isMatch(s.substring(1), p);
            else return isMatch(s, p.substring(2));
        else if (p.charAt(0) == '.' || s.charAt(0) == p.charAt(0)) return isMatch(s.substring(1), p.substring(1));
        else return false;
    }
}