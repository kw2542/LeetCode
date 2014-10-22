class Solution {
public:
    bool isPalindrome(string s) {
        const char *end = s.c_str();
        const char *start = end;
        while (*end != '\0') ++end;
        --end;
        while (start < end) {
            if (false == isAlphanumeric(*start)) ++start;
            else if (false == isAlphanumeric(*end)) --end;
            else if (*start == *end || abs(*start - *end) == 'a' - 'A') {
                ++start;
                --end;
            } else return false;
        }
        return true;
    }
    bool isAlphanumeric (char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z');
    }
};