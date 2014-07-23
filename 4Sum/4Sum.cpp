class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &num, int target) {
        vector<int> _num(num);
        vector<vector<int>> res;
        sort(_num.begin(), _num.end());
        for (int t = 0; t < _num.size(); ++ t) {
            if (t != 0 && _num[t] == _num[t - 1]) continue;
            for (int i = t + 1; i < _num.size(); ++i) {
                if (i != t + 1 && _num[i] == _num[i - 1]) continue;
                int j = i + 1;
                int k = _num.size() - 1;
                while (j < k) {
                    int sum = _num[t] + _num[i] + _num[j] + _num[k];
                    if (sum == target) {
                        vector<int> tmp;
                        tmp.push_back(_num[t]);
                        tmp.push_back(_num[i]);
                        tmp.push_back(_num[j]);
                        tmp.push_back(_num[k]);
                        res.push_back(tmp);
                        ++j;
                        --k;
                        while (j < k && _num[j] == _num[j - 1]) ++j;
                        while (j < k && _num[k] == _num[k + 1]) --k;
                    }
                    else if (sum > target) --k;
                    else ++j;
                }
            }
        }
        return res;
    }
};