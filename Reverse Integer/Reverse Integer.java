public class Solution {
    public int reverse(int x) {
        long res = 0;
        boolean mark = res < 0? true:false;
        while (x != 0) {
            res = res * 10 + x%10;
            x /= 10;
        }
        if (mark) res = -res;
        if (res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        else if (res < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        else return (int)res;
    }
}