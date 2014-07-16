class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int number[4] = {num / 1000, num / 100 % 10, num / 10 % 10, num % 10};
        
        string One[4]  = {"M", "C", "X", "I"};
        string Five[4] = {" ", "D", "L", "V"};
 
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
};