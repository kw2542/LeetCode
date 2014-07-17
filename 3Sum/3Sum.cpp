class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<int> _num(num);
        vector<vector<int>> res;
        sort(_num.begin(), _num.end());
        for (int i = 0; i < _num.size(); ++i) {
            if (i != 0 && _num[i] == _num[i - 1]) continue;
            
            int j = i + 1;
            int k = _num.size() - 1;
            while (j < k) {
                int sum = _num[i] + _num[j] + _num[k];
                if (sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(_num[i]);
                    tmp.push_back(_num[j]);
                    tmp.push_back(_num[k]);
                    res.push_back(tmp);
                    ++j;
                    --k;
                    while (j < k && _num[j] == _num[j - 1]) ++j;
                    while (j < k && _num[k] == _num[k + 1]) --k;
                }
                else if (sum > 0) --k;
                else ++j;
            }
            
        }
        return res;
    }
};