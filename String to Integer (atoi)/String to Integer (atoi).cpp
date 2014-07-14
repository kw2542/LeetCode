class Solution {
public:
    int atoi(const char *str) {
        long long res = 0;
        bool isNegative = false;
        while (*str == ' ') ++str;
        if (*str == '-') {
            isNegative = true;
            ++str;
        } else if (*str == '+') ++str;
        for (; *str >= '0' && *str <= '9'; ++str) {
            res = 10 * res + *str - '0';
        }
        if (isNegative) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        else if (res < INT_MIN) res = INT_MIN;
        return static_cast<int>(res);
    }
};