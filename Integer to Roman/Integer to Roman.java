public class Solution {
    public String intToRoman(int num) {
        String res = "";
        int[] number = {num / 1000, num / 100 % 10, num / 10 % 10, num % 10};
        
        String[] One  = {"M", "C", "X", "I"};
        String[] Five = {" ", "D", "L", "V"};
 
        for (int i = 0; i < 4; ++i) {
            if (number[i] == 9) res += One[i] + One[i - 1];
            else if (number[i] >=5) {
                res += Five[i];
                for (;number[i] > 5; --number[i]) res += One[i];
            }
            else if (number[i] == 4) res += One[i] + Five[i];
            else for (;number[i] > 0; --number[i]) res += One[i];
        }
        return res;
    }
}