public class Solution {
    public List<List<Integer>> subsets(int[] S) {
        Arrays.sort(S);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        for (int i = 0; i <= S.length; ++i) {
            List<List<Integer>> tmp = new ArrayList<List<Integer>>();
            subsetsOfKHelper(tmp, new ArrayList<Integer>(), 0, S, i);
            res.addAll(tmp);
        }
        return res;
    }
    private void subsetsOfKHelper(List<List<Integer>> res, List<Integer> list, int start, int[] S, int k) {
        if (list.size() == k) {
            res.add(new ArrayList(list));
            return;
        }
        for (int i = start; i < S.length; ++i) {
            list.add(S[i]);
            subsetsOfKHelper(res, list, i + 1, S, k);
            list.remove(list.size() - 1);
        }
    }
}