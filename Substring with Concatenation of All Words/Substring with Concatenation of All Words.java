public class Solution {
	public List<Integer> findSubstring(String S, String[] L) {
        List<Integer> res = new ArrayList<Integer>();
        if (0 == L.length || 0 == L[0].length()) return res;
        
		Map<String, Integer> mainMap = new HashMap<String, Integer>();
		for (String s : L) {
			if (true == mainMap.containsKey(s)) mainMap.put(s, mainMap.get(s) + 1);
			else mainMap.put(s, 1);
		}
		
		int num = L.length;
		int len = L[0].length();
		HashMap<String, Integer> map = new HashMap<String, Integer>();

		for (int i = 0; i <= S.length() - num * len; ++i) {
			map.clear();
			for (int j = 0; j < L.length; ++j) {
				String word = S.substring(i + len * j, i + len * j + len);
				if (false == mainMap.containsKey(word)) break;
				else if (false == map.containsKey(word)) {
					map.put(word, 1);
				} else {
					map.put(word, map.get(word) + 1);
				}
				if (map.get(word) > mainMap.get(word)) break;
				if (j == L.length - 1) res.add(i);
			}
		}
        return res;
    }
}