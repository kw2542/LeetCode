class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        const char *p = s.c_str();
        for (;*p != '\0'; ++p) {    
            if(*p == '(' || *p == '[' || *p == '{') stack.push(*p);
            else {
                if (stack.size() == 0) return false;
                char c = stack.top(); 
                stack.pop();
                if (c == '(') 
                    if (*p == ')') continue;
                    else return false;
                else if (c == '[')
                    if (*p == ']') continue;
                    else return false;
                else if (c == '{')
                    if (*p == '}') continue;
                    else return false;
            }
        } 
        if (stack.size() == 0) return true; 
        else return false;
    }
};