public class Solution {
    public String multiply(String num1, String num2) {
        String res = "0";
        char[] nums = num2.toCharArray();
        for (int i = 0; i < nums.length; ++i) {
            if (!res.equals("0")) res = res + "0";
            int len = Character.getNumericValue(nums[i]);
            for (int j = 0; j < len; ++j) {
                res = addition(res, num1);
            }
        }
        return res;
    }
    private String addition(String num1, String num2) {
        char[] num_1 = num1.toCharArray();
        char[] num_2 = num2.toCharArray();
        char[] res;
        char[] num;
        if (num_1.length > num_2.length) {
            res = new char[num_1.length + 1];
            num = new char[num_1.length + 1];
            System.arraycopy(num_1, 0, res, 1, num_1.length);
            System.arraycopy(num_2, 0, num, num_1.length - num_2.length + 1, num_2.length);
        } else {
            res = new char[num_2.length + 1];
            num = new char[num_2.length + 1];
            System.arraycopy(num_2, 0, res, 1, num_2.length);
            System.arraycopy(num_1, 0, num, num_2.length - num_1.length + 1, num_1.length);
        }
        int shift = 0;
        for (int i = res.length - 1; i > 0; --i) {
        	if (num[i] > '0') res[i] += num[i] + shift - '0';
        	else res[i] += shift;
            if (res[i] > '9') {
                res[i] -= 10;
                shift = 1;
            } else shift = 0;
        }
        if (shift == 1) res[0] = '1';
        return String.valueOf(res).trim();
    }
}
/* Solution from ninechapter *
 * Better than mine *
 * Try to Use build in multiply calculation to make it more time efficient */

/*
public class Solution {
    public String multiply(String num1, String num2) {
        if (num1 == null || num2 == null) {
            return null;
        }
        
        int len1 = num1.length(), len2 = num2.length();
        int len3 = len1 + len2;
        int i, j, product, carry;

        int[] num3 = new int[len3];
        for (i = len1 - 1; i >= 0; i--) {
            carry = 0;
            for (j = len2 - 1; j >= 0; j--) {
                product = carry + num3[i + j + 1] +
                    Character.getNumericValue(num1.charAt(i)) *
                    Character.getNumericValue(num2.charAt(j));
                num3[i + j + 1] = product % 10;
                carry = product / 10;
            }
            num3[i + j + 1] = carry;
        }

        StringBuilder sb = new StringBuilder();
        i = 0;

        while (i < len3 - 1 && num3[i] == 0) {
            i++;
        }

        while (i < len3) {
            sb.append(num3[i++]);
        }

        return sb.toString();
    }
}
*/