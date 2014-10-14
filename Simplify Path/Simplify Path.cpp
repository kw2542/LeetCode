class Solution {
public:
    string simplifyPath(string path) {
        vector<string> split;
        stringstream ss(path);
        string item;
        while (std::getline(ss, item, delim)) {
            split.push_back(item);
        }
        vector<string> list;
        for (string s : split) {
            if (s.equals(".") || s.equals("")) continue;
            else if (s.equals("..")) {
                if (list.size() > 0) {
                    list.pop_back();
                }
            } else list.add(s);
        }
        string res = "";
        for (String s : list) {
            res.append('/');
            res.append(s);
        }
        if (sb.length() == 0) sb.append('/');
        return sb.toString();
    }
};