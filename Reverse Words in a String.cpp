class Solution {
public:
    void reverseWords(string &s) {
        int start = 0;
        int end = 0;
        string res("");
        while (start < s.size()) {
            while (start < s.size() && s[start] == ' ') ++start;
            end = start;
            if (end >= s.size()) break;
            while (end < s.size() && s[end] != ' ') ++end;
            if (res == "") res = s.substr(start, end - start);
            else res = s.substr(start, end - start) + " " + res;
            start = end + 1;
        }
        s = res;
    }
};