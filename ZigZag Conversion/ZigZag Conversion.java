public class Solution {
    public String convert(String s, int nRows) {
        if (nRows <= 1) return s;
        final int key = 2 * nRows - 2;
        final int length = s.length();
        char[] c = s.toCharArray();
        StringBuilder res= new StringBuilder("");
        for (int i = 0; i < nRows; ++i) {
            for (int j = i; j < length; j += key) {
                res.append(c[j]);
                if (i > 0 && i < nRows - 1 && j + key - 2 * i < length) res.append(c[j + key - 2 * i]); 
            }
        }
        return res.toString();
    }
}