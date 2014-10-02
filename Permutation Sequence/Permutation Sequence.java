public class Solution {
    public String getPermutation(int n, int k) {
        int totalNum = 1;
        for (int i = 1; i <= n; ++i) {
            totalNum *= i;
        }
        k = k - 1; // set the start to be 0;
        StringBuilder sb = new StringBuilder();
        List<Integer> validNumber = new ArrayList<Integer>();
        for (int i = 1; i <= n; ++i) {
            validNumber.add(i);
        }
        for (int i = n; i > 0; --i) {
            totalNum /= i;
            int index = k / totalNum;
            sb.append(validNumber.get(index));
            validNumber.remove(index);
            k = k % totalNum;
        }
        return sb.toString();
        
    }
}