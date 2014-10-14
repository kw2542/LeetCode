class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> list;
        combine(res, list, 1, n, k);
        return res;
    }
    void combine(vector<vector<int> > &res, vector<int> &list, int start, int n, int k) {
        if (list.size() == k) {
            res.push_back(vector<int>(list));
            return;
        }
        for (int i = start; i <= n; ++i) {
            list.push_back(i);
            combine(res, list, i + 1, n, k);
            list.pop_back();
        }
    }
    
};