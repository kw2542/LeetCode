class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (*needle == '\0') return haystack;
        while (*haystack != '\0') {
            if (*haystack == *needle) {
                char *p = needle;
                char *start = haystack;
                while (*haystack == *p && *haystack != '\0') {
                    ++haystack;
                    ++p;
                }
                if (*p == '\0') return start;
                else if (*haystack == '\0') return nullptr;
                else haystack = start + 1;
            }
            else ++haystack;
        }
        return nullptr;
    }
};