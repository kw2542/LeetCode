public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        return combinationSum2(candidates, candidates.length - 1, target);
    }
    private List<List<Integer>> combinationSum2(int[] candidates, int num, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (target == 0) {
            res.add(new ArrayList<Integer>());
            return res;
        }
        if (target < candidates[0]) return res;
        for (int i = num; i >= 0; --i) {
        	List<List<Integer>> tmp;
            if (target >= candidates[i]) {
                tmp = combinationSum2(candidates, i - 1, target - candidates[i]);
                if (tmp.size() != 0) {
                    for (List<Integer> l : tmp) {
                        l.add(candidates[i]);
                        res.add(l);
                    }
                }
            }
            while (i > 0 && candidates[i] == candidates[i - 1]) --i;
        }
        return res;
    }
}