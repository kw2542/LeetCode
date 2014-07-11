class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        bool mark = res < 0 ? true : false;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (mark) res = -res;
        if (res > INT_MAX) return INT_MAX;
        else if (res < INT_MIN) return INT_MIN;
        else return (int)res;
    }
};