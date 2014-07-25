public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        if (n == 0) return res;
        else if (n == 1) {
            res.add("()");
            return res;
        } else {
            List<String> temp = generateParenthesis(n - 1);
            for (String s : temp) {
                for (int i = 0; i <= s.length(); ++i) {
                	String ss = new StringBuilder(s).insert(i, "()").toString();
                    if (res.contains(ss) == false) res.add(ss);
                }
            }
            return res;
        }
    }
}