class Solution {
public:
    double pow(double x, int n) {
        if (x == 1) return x;
        else if (x == -1) return n % 2 == 0 ? 1 : -1;
        else if (n == 0) return 1;
        else {
            double i = pow(x, n / 2);
            if (n % 2 == 0) {
                return i * i;
            } else {
                if (n < 0) return i * i / x;
                else return i * i * x;
            }
        }
    }
};