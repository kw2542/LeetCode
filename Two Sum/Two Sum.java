public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int[] res = new int[2];
        Integer index = -1;
        for (int i = 0; i < numbers.length; ++i) {
            if ((index = map.get(target - numbers[i])) != null) {
                res[0] = index;
                res[1] = i + 1;
                return res;
            } else {
                map.put(numbers[i], i + 1);
            }
        }
        return res;
    }
}