public class Solution {
    public int numTrees(int n) {
        return numTrees(n, new HashMap<Integer, Integer>());
    }
    private int numTrees(int n, Map<Integer, Integer> map) {
        if (n == 0 || n == 1) return 1;
        else if (map.containsKey(n)) return map.get(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += numTrees(i, map) * numTrees(n - i - 1, map);
        }
        map.put(n, res);
        return res;
    }
}