class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0' && *p == '\0') return true;
        else if (*p == '\0') return false;
        else if (*s == '\0')
            if (*(p + 1) == '*') return isMatch(s, p + 2);
            else return false;
        if (*(p + 1) == '*')
            if (*s == *p || *p == '.') return isMatch(s, p + 2) || isMatch(s + 1, p);
            else return isMatch(s, p + 2);
        else if (*p == '.' || *s == *p) return isMatch(s + 1, p + 1);
        else return false;
    }
};