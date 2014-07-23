class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() < 1) return "";
        int index = 0;
        while (true) {
            if (index >= strs[0].size()) return strs[0];
            for (int i = 1; i < strs.size(); ++i)
                if (strs[i].size() < index + 1 || strs[0][index] != strs[i][index])
                    return strs[0].substr(0, index);
            ++index;
        }
    }
};