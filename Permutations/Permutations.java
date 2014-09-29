public class Solution {
    public List<List<Integer>> permute(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Arrays.sort(num);
        permute(res, new ArrayList<Integer>(num.length), new boolean[num.length], num);
        return res;
    }
    private void permute(List<List<Integer>> res, List<Integer> tmp, boolean[] visited, int[] num) {
        if (tmp.size() == num.length) {
            res.add(new ArrayList(tmp));
        }
        for (int i = 0; i < num.length; ++i) {
            if (true == visited[i] || (i != 0 && num[i] == num[i-1] && visited[i - 1] == true)) continue;
            tmp.add(num[i]);
            visited[i] = true;
            permute(res, tmp, visited, num);
            visited[i] = false;
            tmp.remove(tmp.size() - 1);
        }
    }
}