class Solution {
public:
    string simplifyPath(string path) {
        vector<string> split;
        stringstream ss(path);
        string item;
        while (std::getline(ss, item, '/')) {
            split.push_back(item);
        }
        vector<string> list;
        for (string s : split) {
            if (!s.compare(".") || !s.compare("")) continue;
            else if (!s.compare("..")) {
                if (list.size() > 0) {
                    list.pop_back();
                }
            } else list.push_back(s);
        }
        string res = "";
        for (string s : list) {
            res.append("/");
            res.append(s);
        }
        if (res.length() == 0) res.append("/");
        return string(res);
    }
};