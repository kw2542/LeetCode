public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        combine(res, new ArrayList<Integer>(), 1, n, k);
        return res;
    }
    private void combine(List<List<Integer>> res, List<Integer> list, int start, int n, int k) {
        if (list.size() == k) {
            res.add(new ArrayList<Integer>(list));
            return;
        }
        for (int i = start; i <= n; ++i) {
            list.add(i);
            combine(res, list, i + 1, n, k);
            list.remove(list.size() - 1);
        }
    }
}