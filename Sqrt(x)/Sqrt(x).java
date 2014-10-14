public class Solution {
    public int sqrt(int x) {
        double last = 1;
        double val = last;
        do {
            last = val;
            val = (val + x / val) * 0.5;
        } while (Math.abs(last - val) >= 1);
        return (int)val;
    }
}