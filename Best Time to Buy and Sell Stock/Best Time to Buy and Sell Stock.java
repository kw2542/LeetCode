public class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        int tmp = 0;
        for (int i = 0; i < prices.length - 1; ++i) {
            tmp += prices[i + 1] - prices[i];
            max = Math.max(max, tmp);
            if (tmp < 0) tmp = 0;
        }
        return max;
    }
}