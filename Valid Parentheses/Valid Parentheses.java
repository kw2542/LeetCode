public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); ++i) {
            char p = s.charAt(i);
            if(p == '(' || p == '[' || p == '{') stack.push(p);
            else {
                if (stack.size() == 0) return false;
                char c = stack.pop();
                if (c == '(') 
                    if (p == ')') continue;
                    else return false;
                else if (c == '[')
                    if (p == ']') continue;
                    else return false;
                else if (c == '{')
                    if (p == '}') continue;
                    else return false;
            }
        } 
        if (stack.size() == 0) return true; 
        else return false;
    }
}