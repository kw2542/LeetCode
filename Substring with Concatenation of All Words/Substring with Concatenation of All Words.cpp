class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (0 == S.size() || 0 == L.size()) return res;
        
        int num = L.size();
        int len = L[0].size();
        unordered_map<string, int> main_map;
        for (string s : L) {
            if (main_map.find(s) == main_map.end()) main_map[s] = 1;
            else main_map[s] = main_map[s] + 1;
        }
        
        unordered_map<string, int> map;
        int ss = S.size();
        for (int i = 0; i <= ss - len * num; ++i) {
            map.clear();
            for (int j = 0; j < num; ++j) {
                string s = S.substr(i +  j * len, len);
                auto main_it = main_map.find(s);
                if (main_it == main_map.end()) break;
                auto it = map.find(s);
                if (it == map.end()) map[s] = 1;
                else {
                    it->second += 1;
                    if (it->second > main_it->second) break;
                }
                if (j == num - 1) res.push_back(i);
            }
        }
        return res;
    }
};