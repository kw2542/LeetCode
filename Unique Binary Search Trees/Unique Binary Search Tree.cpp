class Solution {
public:
    int numTrees(int n) {
        unordered_map<int, int> map;
        return numTrees(n, map);
    }
    int numTrees(int n, unordered_map<int, int> &map) {
        if (n == 1 || n == 0) return 1;
        else {
            auto it = map.find(n);
            if (it != map.end()) return it->second;
            int res = 0;
            for (int i = 0; i < n; ++i) {
                res += numTrees(i, map) * numTrees(n - i - 1, map);
            }
            map[n] = res;
            return res;
        }
    }
};