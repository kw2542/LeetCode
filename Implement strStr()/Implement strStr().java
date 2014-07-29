public class Solution {
    public String strStr(String haystack, String needle) {
        if(haystack == null || needle == null) return null;
        else if (needle.length() == 0) return haystack;
        for(int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            for(int j = 0; j < needle.length(); j++) {
                if(haystack.charAt(i + j) != needle.charAt(j)) break;
                if(j == needle.length() - 1) return haystack.substring(i);
            }
        }
        return null;
    }
}