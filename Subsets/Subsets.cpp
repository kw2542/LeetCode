class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > res;
        for (int i = 0; i <= S.size(); ++i) {
            vector<vector<int> > tmp;
            vector<int> list;
            subsetsOfKHelper(tmp, list, 0, S, i);
            for (vector<int> vec : tmp) {
                res.push_back(vec);
            }
        }
        return res;
    }
    void subsetsOfKHelper(vector<vector<int> > &res, vector<int> &list, int start, vector<int> &S, int k) {
        if (list.size() == k) {
            res.push_back(vector<int>(list));
            return;
        }
        for (int i = start; i < S.size(); ++i) {
            list.push_back(S[i]);
            subsetsOfKHelper(res, list, i + 1, S, k);
            list.pop_back();
        }
    }
};