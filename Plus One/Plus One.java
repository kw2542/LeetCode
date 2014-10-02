public class Solution {
    public int[] plusOne(int[] digits) {
        int shift = 1;
        int[] res;
        for (int i = digits.length - 1; i >= 0; --i) {
            int sum = digits[i] + shift;
            shift = sum / 10;
            digits[i] = sum % 10;
        }
        if (shift != 0) {
            res = new int[digits.length + 1];
            System.arraycopy(digits, 0, res, 1, digits.length);
            res[0] = shift;
        } else {
            res = new int[digits.length];
            System.arraycopy(digits, 0, res, 0, digits.length);
        }
        return res;
    }
}