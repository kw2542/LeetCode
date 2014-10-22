class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
        } else if (n == 1) {
            res.push_back(0);
            res.push_back(1);
        } else if (n > 1) {
            vector<int> tmp = grayCode(n - 1);
            for (int i : tmp) {
                res.push_back(i);
            }
            tmp = reverseList(tmp);
            for (int i : tmp) {
                res.push_back(i | (1 << (n - 1)));
            }
        }
        return res;
    }
    vector<int> reverseList(vector<int> &list) {
        vector<int> res;
        for (int i = list.size() - 1; i >= 0; --i) {
            res.push_back(list[i]);
        }
        return res;
    }
};