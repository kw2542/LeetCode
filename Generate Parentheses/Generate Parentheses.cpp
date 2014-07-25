class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        else if (n == 1) {
            res.push_back("()");
            return res;
        } else {
            vector<string> temp = generateParenthesis(n - 1);
            for (string s : temp) {
                for (int i = 0; i <= s.size(); ++i) {
                    string ss = s;
                    ss.insert(i, "()");
                    if (find(res.begin(), res.end(), ss) == res.end()) res.push_back(ss);
                }
            }
            return res;
        }
    }
};