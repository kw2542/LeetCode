public class Solution {
    public String countAndSay(int n) {
        return countAndSay(n, new HashMap<Integer, String>());
    }
    private String countAndSay(int n, Map<Integer, String> map) {
    	if (n == 1) return "1";
        if (map.containsKey(n)) return map.get(n);
        char[] c = countAndSay(n - 1).toCharArray();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < c.length;) {
            char cc = c[i];
            int count = 0;
            while (i < c.length && cc == c[i]) {
                ++i;
                ++count;
            }
            sb.append(count);
            sb.append(cc);
        }
        map.put(n, sb.toString());
        return sb.toString();
    }
}