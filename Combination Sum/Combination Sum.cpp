class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSum(candidates, candidates.size() - 1, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int num, int target) {
        vector<vector<int> > res;
        if (target == 0) {
            res.push_back(vector<int>(0));
            return res;
        }
        if (target < candidates[0]) return res;
        for (int i = num; i >= 0; --i) {
        	vector<vector<int>> tmp;
            if (target >= candidates[i]) {
                tmp = combinationSum(candidates, i, target - candidates[i]);
                if (tmp.size() != 0) {
                    for (vector<int> l : tmp) {
                        l.push_back(candidates[i]);
                        res.push_back(l);
                    }
                }
            }
        }
        return res;
    }
};