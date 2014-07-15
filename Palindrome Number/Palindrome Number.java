public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int y = x;
        int div = 1;
        for (; y / 10 != 0; y /= 10) {
            div *= 10;
        }
        for (;div > 0;) {
            if (x/div != x%10) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
}