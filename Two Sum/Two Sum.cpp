class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res(2);
        unordered_map<int, int> map(numbers.size());
        for (int i = 0; i < numbers.size(); ++i) {
            auto it = map.find(target - numbers[i]);
            if (it != map.end()) {
                res[0] = it->second;
                res[1] = i + 1;
                return res;
            } else {
                map[numbers[i]] = i + 1;
            }
        }
        return res;
    }
};