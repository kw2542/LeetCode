public class Solution {
    public void nextPermutation(int[] num) {
        int len = num.length;
        for (int i = len - 1; i > 0; --i) {
            if (num[i] > num[i - 1]) {
                int j = i;
                while (j < len && num[j] > num[i - 1]) ++j;
                int t = num[j - 1];
                num[j - 1] = num[i - 1];
                num[i - 1] = t;
                Arrays.sort(num, i, len);
                break;
            }
            if (i == 1) Arrays.sort(num);
        }
    }
}