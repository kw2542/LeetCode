class Solution {
public:
    string countAndSay(int n) {
        string old = "1";
        while (--n > 0) {
            string s = "";
            const char *c = old.c_str();
            for (int i = 0; i < old.size();) {
                int count = 0;
                char cc = c[i];
                while (i < old.size() && cc == c[i]) {
                    ++i;
                    ++count;
                }
                s += to_string(count);
                s += cc;
            }
            old = s;
        }
        return old;
    }
};