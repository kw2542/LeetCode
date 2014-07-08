public class Solution {
    public String reverseWords(String s) {
        String[] split = s.split("\\s+");
        StringBuffer res = new StringBuffer();
        for (int i = split.length - 1; i >= 0 ; --i) {
            res.append(split[i]); 
            res.append(" ");
        }
        return res.toString().trim();
    }
}