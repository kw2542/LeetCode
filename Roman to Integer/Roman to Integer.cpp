class Solution {
public:
    int romanToInt(string s) {
        if (s.size()==0) return 0;
	    unordered_map<char, int> map;
	    map['I'] = 1;
	    map['V'] = 5;
	    map['X'] = 10;
	    map['L'] = 50;
	    map['C'] = 100;
	    map['D'] = 500;
	    map['M'] = 1000;

	    int len = s.size();
	    int result = map[s[len - 1]];
	    for (int i = len - 2; i >= 0; i--)
	        if (map[s[i + 1]] <= map[s[i]]) result += map[s[i]]; 
	        else result -= map[s[i]];
	    return result;
    }
};