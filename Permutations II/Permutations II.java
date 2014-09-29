public class Solution {
    public List<List<Integer>> permuteUnique(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Arrays.sort(num);
        permuteUnique(res, new ArrayList<Integer>(num.length), new boolean[num.length], num);
        return res;
    }
    private void permuteUnique(List<List<Integer>> res, List<Integer> tmp, boolean[] visited, int[] num) {
        if (tmp.size() == num.length) {
            res.add(new ArrayList(tmp));
        }
        for (int i = 0; i < num.length; ++i) {
            if (true == visited[i] || (i != 0 && num[i] == num[i-1] && visited[i - 1] == true)) continue;
            tmp.add(num[i]);
            visited[i] = true;
            permuteUnique(res, tmp, visited, num);
            visited[i] = false;
            tmp.remove(tmp.size() - 1);
        }
    }
}