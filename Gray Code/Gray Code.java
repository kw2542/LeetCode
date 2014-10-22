public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        if (n == 0) {
            res.add(0);
        } else if (n == 1) {
            res.add(0);
            res.add(1);
        } else if (n > 1) {
            List<Integer> tmp = grayCode(n - 1);
            res.addAll(tmp);
            tmp = reverseList(tmp);
            for (Integer i : tmp) {
                res.add(i | (1 << (n - 1)));
            }
        }
        return res;
    }
    private List<Integer> reverseList(List<Integer> list) {
        List<Integer> res = new ArrayList<>();
        for (int i = list.size() - 1; i >= 0; --i) {
            res.add(list.get(i));
        }
        return res;
    }
}