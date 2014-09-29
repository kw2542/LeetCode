class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> visited(num.size(), false);
        permute(res, tmp, visited, num);
        return res;
    }
    void permute(vector<vector<int>> &res, vector<int> &tmp, vector<bool> visited, vector<int> &num) {
        if (tmp.size() == num.size()) {
            res.push_back(tmp);
        }
        for (int i = 0; i < num.size(); ++i) {
            if (true == visited[i] || (i != 0 && num[i] == num[i-1] && visited[i - 1] == true)) continue;
            tmp.push_back(num[i]);
            visited[i] = true;
            permute(res, tmp, visited, num);
            visited[i] = false;
            tmp.pop_back();
        }
    }
};