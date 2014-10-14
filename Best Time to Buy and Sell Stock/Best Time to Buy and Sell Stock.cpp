class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < (int)prices.size() - 1; ++i) {
            tmp += prices[i + 1] - prices[i];
            res = max(res, tmp);
            if (tmp < 0) tmp = 0;
        }
        return res;
    }
};