class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
        int *first = new int[prices.size()];
        int *second = new int[prices.size()];
        
        int MIN = prices[0];
        first[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            MIN = min(MIN, prices[i]);
            first[i] = max(first[i - 1], prices[i] - MIN);
        }
        
        int MAX = prices[prices.size() - 1];
        second[prices.size() - 1] = 0;
        for (int i = prices.size() - 2; i >=0; --i) {
            MAX = max(MAX, prices[i]);
            second[i] = max(second[i + 1], MAX - prices[i]);
        }
        
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            res = max(res, first[i] + second[i]);
        }
        return res;
    }
};