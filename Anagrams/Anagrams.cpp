class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); ++i) {
            string s = string(strs[i]);
            sort(s.begin(), s.end());
            auto it = map.find(s);
            if (it == map.end()) {
                vector<string> list;
                list.push_back(strs[i]);
                map[s] = list;
            } else {
                it->second.push_back(strs[i]);
            }
        }
        vector<string> res;
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->second.size() > 1) {
                for (string s : it->second) {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};