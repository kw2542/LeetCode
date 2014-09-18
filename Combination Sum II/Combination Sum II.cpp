class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSum2(candidates, candidates.size() - 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int num, int target) {
        vector<vector<int> > res;
        if (target == 0) {
            res.push_back(vector<int>(0));
            return res;
        }
        if (target < candidates[0]) return res;
        for (int i = num; i >= 0; --i) {
        	vector<vector<int>> tmp;
            if (target >= candidates[i]) {
                tmp = combinationSum2(candidates, i - 1, target - candidates[i]);
                if (tmp.size() != 0) {
                    for (vector<int> l : tmp) {
                        l.push_back(candidates[i]);
                        res.push_back(l);
                    }
                }
            }
            while (i > 0 && candidates[i] == candidates[i - 1]) --i;
        }
        return res;
    }
};