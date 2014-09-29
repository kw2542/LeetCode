class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *pre_s = s;
        const char *pre_p = p;
        bool has_star = false;  
        while (*s) {
            if (*p == '*') {
                has_star = true;  
                while (*p == '*') ++p;
                if (*p == '\0') return true;
                pre_s = s;
                pre_p = p;
            } else if (*p == '?' || *p == *s) {
                ++s;
                ++p;
            } else if (has_star) {
                ++pre_s;
                s = pre_s;
                p = pre_p;
            } else return false;
        }  
        while (*p == '*') p++;  
        return *p == '\0';
    }
};